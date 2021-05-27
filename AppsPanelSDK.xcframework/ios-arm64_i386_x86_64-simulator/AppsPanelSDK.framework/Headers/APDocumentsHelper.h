//
//  APDocumentsHelper.h
//  AppsPanelSDKV3
//
//  Created by Pierre on 02/10/2017.
//  Copyright © 2017 Apps-Panel. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface APDocumentsHelper : NSObject

+ (void)writeValue:(id) value forKey:(NSString *)key;
+ (void)writeValue:(id) value forKey:(NSString *)key inPlist:(NSString *)plistName;
+ (id)readValueForKey:(NSString *)key;
+ (id)readValueForKey:(NSString *)key fromPlist:(NSString *) plistName;

@end

