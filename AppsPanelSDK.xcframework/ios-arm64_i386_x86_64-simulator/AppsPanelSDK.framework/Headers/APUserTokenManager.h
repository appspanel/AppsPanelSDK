//
//  APUserTokenManager.h
//  AppsPanelSDK
//
//  Created by Simon BRUILLOT on 02/08/2017.
//  Copyright © 2017 Apps Panel. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface APUserTokenManager : NSObject

+ (instancetype) sharedInstance;

/**
 Saves the user's session token to the keychain.

 @param token The user token to save.
 */
- (void)saveToken:(NSString*)token;

/**
 Deletes the user's session token from the keychain.
 */
- (void)deleteToken;

/**
 Retrieves the user's session token from the keychain.

 @return A NSString containing the user's session token.
 */
- (NSString *)getToken;


@end
