
import time
import click
from platformio.public import TestRunnerBase
from platformio.device.finder import SerialPortFinder
from platformio.exception import UserSideException
from platformio.public import TestCase
from platformio.public import TestStatus

from ebs.tests.serial import serial_test


class CustomTestRunner(TestRunnerBase):
    _test_name = "Throughput Test"
    _actual = serial_test.run_throughput_test
    _length = 1000000
    SERIAL_TIMEOUT = 600

    def _run_test(self):
        params = self._get_port_params()
        params['length'] = self._length
        result = CustomTestRunner._actual(**params)
        
        if result['pass']:
            self.test_suite.add_case(TestCase(
                    name=self._test_name, 
                    status=TestStatus.PASSED, 
                    duration=result["duration"]))
        else:
            self.test_suite.add_case(TestCase(
                    name=self._test_name,
                    status=TestStatus.FAILED,
                    message=result["msg"],
                    duration=result["duration"]))
        return

    def stage_testing(self):
        if self.options.without_testing:
            return None
        if not click.confirm(f'Run {self._test_name}?', default=True):
            return
        click.secho("Testing...", bold=True)
        time.sleep(3)
        self._run_test()
    
    def _get_port_params(self):
        return {
            'url': self.resolve_test_port(),
            'baudrate': self.get_test_speed(),
            'timeout': self.SERIAL_TIMEOUT
        }

    def resolve_test_port(self) :
        project_options = self.project_config.items(
            env=self.test_suite.env_name, as_dict=True
        )
        port = SerialPortFinder(
            board_config=self.platform.board_config(
                project_options["board"]
            ),
            upload_protocol=project_options.get("upload_protocol"),
            ensure_ready=True,
            verbose=self.options.verbose,
        ).find(initial_port=self.get_test_port())
        if port:
            return port
        raise UserSideException(
            "Please specify `test_port` for environment or use "
            "global `--test-port` option."
        )

