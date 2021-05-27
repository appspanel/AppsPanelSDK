//
//  Cryptage.h
//  AppsPanelSDKV3
//
//  Created by Allan bouvard on 16/09/2015.
//  Copyright (c) 2015 Apps-Panel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 An NSData categorie that allows you to crypt data with the AES256 protocol
 */
@interface NSData(AES)

/*!
 @abstract Encrypt self using a predifined key
 
 @return Data encrypted with the key
 
 @see AES256DecryptedData
 */
- (NSData *)AES256EncryptedData;

/*!
 @abstract Decrypt self using a predifined key
 
 @return Decrypted data
 
 @see AES256EncryptedData
 */
- (NSData *)AES256DecryptedData;

/*!
 @abstract Encrypt self with the given key
 
 @param key The key to used to encrypt the data
 
 @return Data encrypted with the key
 
 @see AES256DecryptedDataWithKey:
 */
- (NSData *)AES256EncryptedDataWithKey:(NSString *)key;

/*!
 @abstract Decrypt self with the given key
 
 @param key The key to used to decrypt the data

 @return Decrypted data
 
 @see AES256EncryptedDataWithKey:
 */
- (NSData *)AES256DecryptedDataWithKey:(NSString *)key;

/*!
 @abstract Encrypt self with the given key
 
 @param key The key to use to encrypt the data
 
 @param iv The iv to use to encrypt the data
 
 @return Data encrypted with the key and the iv
 
 @see AES256EncryptWithKey:
 */
- (NSData *)AES256EncryptedDataWithKey:(NSString *)key iv:(NSString *)iv;

/*!
 @abstract Decrypt self with the given key
 
 @param key The key to use to decrypt the data
 
 @param iv The iv to use to decrypt the data
 
 @return Data encrypted with the key and the iv
 
 @see AES256EncryptWithKey:
 */
- (NSData *)AES256DecryptedDataWithKey:(NSString *)key iv:(NSString *)iv;


@end
