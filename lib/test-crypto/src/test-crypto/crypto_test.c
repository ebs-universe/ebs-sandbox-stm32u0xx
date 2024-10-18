

#include "test_crypto.h"
#include <string.h>

/*
Sample data from test_aes_gcm.py

  Message: "Example message for encryption"
      Key: 0x000102030405060708090a0b0c0d0e0f
       IV: 0x414243123456789000000000
Encrypted: 0xc79af4cfbb73ec2a6013943e061c81c7583cc09f1e563054031b8def08a5
           199 154 244 207 187 115 236 42 96 19 148 62 6 28 129 199 88 60 192 159 30 86 48 84 3 27 141 239 8 165 
  AuthTag: 0xe939ae89c965fa7e99f151c71e1f3753
           233 57 174 137 201 101 250 126 153 241 81 199 30 31 55 83
*/


uint8_t crypto_input[32] = "Example message for encryption";
uint8_t crypto_output[255] = "";


uint8_t crypto_trc_cb(crypto_transaction_t *const tr){
    return 0;
}

crypto_transaction_t crypto_transaction = {
    &crypto_ctx,
    CRYPTO_CTX_MODE_ENCRYPTION,
    CRYPTO_TR_PENDING,
    30,
    0,
    0,
    &crypto_input,
    &crypto_output,
    &crypto_trc_cb,
};


void crypto_demo(void){
    crypto_trigger_transaction(&crypto_transaction);
    return;
}