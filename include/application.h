

#ifndef APPLICATION_H
#define APPLICATION_H

#include <hal/constants/all.h>

// Also see the following files generated by SMT32CubeMX : 
//   include/stm32u0xx_hal_conf.h

#define APP_UCDM_MAX_REGISTERS              255
#define APP_ENABLE_LIBVERSION_DESCRIPTORS   1

/**
 * @name Application GPIO Configuration
 */
/**@{*/   
    #define APP_ENABLE_GPIO            1
/**@}*/ 


/**
 * @name Application Systick and Time Configuration
 */
/**@{*/   
    #define APP_ENABLE_SYSTICK         1
    #define APP_USE_CORE_SYSTICK       1
    #define APP_ENABLE_TIME_CRON       1
    #define APP_ENABLE_TIME_SYNC       1
    #define APP_ENABLE_RTC             1
    #define APP_ENABLE_RTC_1HZ_OUT     1
/**@}*/ 

/**
 * @name Application Device ID Configuration
 */
/**@{*/   
    #define APP_ENABLE_ID               1
    #define APP_ID_TRIMFUNC             1
/**@}*/ 

/**
 * @name Application EEPROM Configuration
 */
/**@{*/
    #define APP_ENABLE_EEPROM           0
/**@}*/ 

/**
 * @name Application Entropy Configuration
 */
/**@{*/   
    #define APP_ENABLE_RAND             1
    #define APP_ENABLE_ENTROPY          APP_ENABLE_RAND
    #define APP_ENTROPY_POOL_SIZE       16
    #define APP_ENTROPY_MODE            2
/**@}*/ 

/**
 * @name Application UART Configuration
 */
/**@{*/   
    #define APP_ENABLE_UART             1

    #define APP_ENABLE_UART1            0
    #define APP_ENABLE_UART2            1    
    #define APP_ENABLE_UART3            0
    #define APP_ENABLE_UART4            0
    #define APP_ENABLE_UART5            0
    #define APP_ENABLE_UART6            0
    #define APP_ENABLE_UART7            0
    
    #define APP_ENABLE_UART2_PT         1
    #define uC_UART2_PT_INFNUM          0
    #define uC_UART2_INTFNUM            0
    #define uC_UART2_BAUD               1000000
    #define uC_UART2_TXBUF_LEN          255
    #define uC_UART2_RXBUF_LEN          255
/**@}*/ 

/**
 * @name Application Primary Interface Configuration
 */
/**@{*/   
    #define APP_ENABLE_PRIF             0
    #define APP_PRIF_TYPE               0
    #define APP_PRIF_INTFNUM            0
/**@}*/ 

/**
 * @name Application Backchannel Interface Configuration
 */
/**@{*/   
    #define APP_ENABLE_BCIF             1
    #define APP_BCIF_TYPE               0
    #define APP_BCIF_INTFNUM            0
/**@}*/ 

#define DLMS_INVOCATION_COUNTER     0x00000000
#define DLMS_MANUFACTURER_CODE      0x414243
#define DLMS_SERIAL_NUMBER          0x1234567890
#define DLMS_SYSTEM_TITLE           ((DLMS_MANUFACTURER_CODE << 40) | DLMS_SERIAL_NUMBER)           

/**
 * @name Application Crypto Configuration
 * 
 * Common Parameters 
 *   - APP_ENABLE_CRYPTO 
 *   - APP_CRYPTO_HARDWARE 
 *   - APP_CRYPTO_INTERRUPT
 * 
 * No Default Context  
 *   - APP_CRYPTO_NO_DEFAULT_CONTEXT
 * 
 * Default Context
 *   - APP_CRYPTO_ALG
 *   - APP_CRYPTO_KEYSIZE
 *   - APP_CRYPTO_IVSIZE
 *   - APP_CRYPTO_KEY
 *   - APP_CRYPTO_IV  
 */
/**@{*/   
    #define APP_ENABLE_CRYPTO           1
    #define APP_CRYPTO_HARDWARE         CRYPTO_HW_ALWAYS
    #define APP_CRYPTO_INTERRUPT        1
    #define APP_CRYPTO_ALG              CRYPTO_AES_GCM
    #define APP_CRYPTO_KEYSIZE          128
    #define APP_CRYPTO_IVSIZE           96
    #define APP_CRYPTO_INGESTSIZE       128
    #define APP_CRYPTO_BLOCKSIZE        0
    #define APP_CRYPTO_HEADERSIZE       0
    #define APP_CRYPTO_MACSIZE          128
    #define APP_CRYPTO_KEY              {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F} 
    #define APP_CRYPTO_IV               ((DLMS_SYSTEM_TITLE << 32) | DLMS_INVOCATION_COUNTER)
    #define APP_CRYPTO_SWAP             CRYPTO_SWAP_NONE
    #define APP_CRYPTO_MODE             CRYPTO_CTX_MODE_ENCRYPTION
/**@}*/

// /**
//  * @name Application USB Configuration
//  */
// /**@{*/    
//     #define APP_ENABLE_USB_HOST             0   // Not implemented.
//     #define APP_ENABLE_USB_DEVICE           1
//     #define APP_ENABLE_USB                  (APP_ENABLE_USB_DEVICE | APP_ENABLE_USB_HOST)
//     #define APP_USB_DEVICE_RHPORT           0
//     #define APP_USB_DESCR_VID               1155
//     #define APP_USB_DESCR_PID               22336
//     #define APP_USB_DESCR_VERSION           0x0100
//     #define APP_USB_DESCR_MANUFACTURER      "EBS Development"
//     #define APP_USB_DESCR_PRODUCT           "STM32F4 Development Sandbox"
//     #define APP_USB_DESCR_IF_CDC            "TinyUSB CDC"
//     #define APP_USB_POWER                   400
//     #define APP_USBCDC_IFACES               1
//     #define APP_USBCDC_IFACE                0
//     #define APP_BLINK_FOR_USB_STATUS        1
// /**@}*/ 

/**
 * @name Application Common Infrastructure Configuration
 */
/**@{*/   
    #define APP_ENABLE_BLINK                 1
/**@}*/

/**
 * @name Application Modbus Configuration
 */
/**@{*/   
    #define APP_ENABLE_MODBUS                1
    
    #if APP_ENABLE_PRIF
        #define MODBUS_TRANSPORT_INTFNUM     APP_PRIF_INTFNUM
        #define MODBUS_TRANSPORT_TYPE        APP_PRIF_TYPE
    #elif APP_ENABLE_BCIF
        #define MODBUS_TRANSPORT_INTFNUM     APP_BCIF_INTFNUM
        #define MODBUS_TRANSPORT_TYPE        APP_BCIF_TYPE
    #endif

    #define MODBUS_PLUGGABLE_TRANSPORTS      0
    #define MODBUS_DEFAULT_DEVICE_ADDRESS    0x05
/**@}*/

/**
 * @name Application Testing Configuration
 */
/**@{*/   
    #ifndef TEST_SERIAL_INTFNUM
        #if APP_ENABLE_PRIF
        #define TEST_SERIAL_INTFNUM           APP_PRIF_INTFNUM
        #define TEST_SERIAL_TYPE              APP_PRIF_TYPE
        #elif APP_ENABLE_BCIF
        #define TEST_SERIAL_INTFNUM           APP_BCIF_INTFNUM
        #define TEST_SERIAL_TYPE              APP_BCIF_TYPE
        #endif
    #endif
    #ifndef TEST_SERIAL_TYPE
    #define TEST_SERIAL_TYPE                  0
    #endif
/**@}*/ 

#endif