//
//  APTextManager.h  v1.0
//  AppsPanelSDKV4
//
//  Created by apnl05 on 22/05/13.
//  Copyright (c) 2013 Nomeo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol APTextManagerDelegate;

/*!
 * The text manager manage all the strings of your application !
 */
@interface APTextManager : NSObject

/*!
 @name Protocol
 */

/*!
 @abstract The delegate will be called when the text manager update is over
 
 @see APTextManagerDelegate
 */
#if __has_feature(objc_arc_weak)
@property (weak) _Nullable id<APTextManagerDelegate> delegate;
#elif __has_feature(objc_arc)
@property (unsafe_unretained) _Nullable id<APTextManagerDelegate> delegate;
#else
@property (assign) _Nullable id<APTextManagerDelegate> delegate;
#endif

/*!
 @name Functions
 */

/*!
 @abstract This method will instanciate the text manager's singleton
 @param langues Lang of the file to download from the server (eg : fr)
 */
+ (void)setDefaultTextDictionary:(nonnull NSString *)langues;

/*!
 @abstract The text manager's singleton
 */
+ (nonnull instancetype)sharedInstance;

/*!
 @abstract Return the number of keys in the current NSDictionnary
 */
+ (NSInteger)numberOfKeys;

/*!
 @abstract Return the number of keys in the current lang file
 @param key The key to retreive in the NSDictionnary
 @returns Value for the given key in the NSDictionnary
 @warning If the given key isn't find in the NSDictionnary, the return will contain the key
 */
+ (nonnull NSString *)stringForKey:(nonnull NSString *)key;

/*!
 @abstract Use it to delete the previous remote file stored in the device for a specific lang
 @param lang Lang of the file to delete (eg : en)
 */
+ (void)clearRemoteFileFromDiskForLang:(nonnull NSString *)lang;

@end

/*!
 The text manager delegate
 */
@protocol APTextManagerDelegate <NSObject>
@optional
/*!
 @abstract Called after the update fail
 @discussion Occur if there is no internet connection available or if the webservice doesn't return an NSDictionnary
 @see textManagerFinishedDownload
 */
- (void)textManagerFailedDownload;

/*!
 @abstract Called after the update succeed
 @see textManagerFailedDownload
 */
- (void)textManagerFinishedDownload;
@end

