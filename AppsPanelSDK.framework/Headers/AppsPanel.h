//
//  AppsPanelSDKV3.h
//  AppsPanelSDKV4
//
//  Created by Allan bouvard on 01/04/2014.
//  Copyright (c) 2014 Apps-Panel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/*!
 @typedef APLogType enum
 
 @abstract To define the log level of the application
 */
typedef NS_ENUM(NSUInteger, APLogType) {
    /*! @abstract No Log */
	APLogTypeNone,
    /*! @abstract Minimum level of log */
    APLogTypeLight,
    /*! @abstract Intermediate level of log */
    APLogTypeWS,
    /*! @abstract Maximum level of log */
	APLogTypeFull,
};

/**
 Security options
 
 - APSecurityModeNone: No additional security
 - APSecurityModeJWTOnly: a JSON Web Token is used to transfer user token and secure data
 - APSecurityModeRequest: all requests execpt GET ones will be encrypted
 - APSecurityModeResponse: Answers from the WS will be encrypted
 - APSecurityModeRequestAndResponse: Encrypts all calls execept GET ones, in and out
 */

typedef NS_ENUM(NSUInteger, APSecurityMode) {
    APSecurityModeNone,
    APSecurityModeJWTOnly,
    APSecurityModeRequest,
    APSecurityModeResponse,
    APSecurityModeRequestAndResponse
};

/** 
 AppsPanel SDK main class.
 It will manage the download of the configuration of your application and activate the modules that should be (eg : Ad, location, ...)
 */
@interface AppsPanel : NSObject

/*!
 @name Application
 */

/*!
 @abstract Name of the current application
 @discussion Equals 'NAME_APP' in the APConflig.plist file
 */
@property (nonatomic, strong) NSString *appName;

/*!
 @abstract Key of the current application
 @discussion Equals 'APP_KEY' in the APConflig.plist file
 */
@property (nonatomic, strong) NSString *appKey;

/**
 The app's secret key.
 */
@property (nonatomic, strong) NSString *appSecret;

/*!
 @abstract A custom base URL used for every HTTP requests.
 @discussion If this value is nil, the SDK uses the default base URL (built with app name).
 */
@property (nonatomic, strong) NSString *baseURL;

/*!
 @abstract Determines if the SDK must use the custom base URL to get the SDK's configuration
 */
@property (nonatomic, assign) BOOL usesBaseURLForSDKConfiguration;

/*!
 @abstract Minimum level of logs to be printed in the console
 */
@property (nonatomic, assign) APLogType logLevel;

/*!
 @abstract Version of the application
 @discussion Equals CFBundleShortVersionString
 @warning if CFBundleShortVersionString equals '1.1', appVersion will be 11 (since version 4.6.0, appVersion will be 1.1 in that case)
 */
@property (nonatomic, retain) NSString *appVersion;

/*!
 @abstract Custom url for specific project
 */
@property (nonatomic, retain) NSString *appBaseUrl;

/*!
@abstract BOOL to determine if sdk url is appBaseUrl (have to be define)
*/
@property (nonatomic, readwrite) BOOL baseUrlSDK;

/**
 Set the security level of the SDK
 
 @param options The desired level of security
 @param randomizeKey If set to YES, a random encryption key will be generated for each call
 */
- (void)securityMode:(APSecurityMode)options randomizeKey:(BOOL)randomizeKey;

@property (nonatomic, readonly) APSecurityMode securityMode;

/*!
 @name Device
 */

/*!
 @abstract Unique identifier of the device
 */
@property (nonatomic, retain) NSString *deviceUDID;


/*!
 @name Singleton
 */

/*!
 @abstract Singleton of the AppsPanel SDK
 */
+ (instancetype) sharedInstance;

/*!
 @name Initialization
 */

/*!
 @abstract Initializes the SDK with the specified configuration
 @discussion By calling this method, you get the configuration from server. You also check for
 @warning You must call this method after setting all configuration properties
 */
- (void)startSession;



/*!
 @name Pushs notifications
 */
 
/*!
 @abstract Must be called to register the device token on the server side. The token will be used to send notification push to the device.
 
 @param adeviceToken deviceToken received in the AppDelegate
 @param app application received in the AppDelegate
 
 @discussion In the AppDelegate's didRegisterForRemoteNotificationsWithDeviceToken method
 */
- (void)registerWithDeviceToken:(NSData *)adeviceToken andApp:(UIApplication *)app;

/**
 @abtract Call this method to show the push notification's authorization popin. Once it has been shown, the SDK will manage everything by its own.
 
 @discussion Please disable the automatic option for push in the SDK configuration if you use this method.
 */
- (void)registerForRemoteNotifications;


/**
 @abstract Sends a patch to the server containing the informations about the state of the push notifications on the user device (ie. enabled or not).
 @discussion This method should be called in the AppDelegate didBecomeActive method
 */
- (void)sendPushPatch;

/*!
 @abstract Check if the application was launch after a click on a push notification
 
 @discussion In the AppDelegate's didFinishLaunchingWithOptions method
 
 @param launchOptions launchOptions received in the AppDelegate

 @see checkForNotificationsAtLaunching:notificationIsSilent:
 */
- (void)checkForNotificationsAtLaunching:(NSDictionary *)launchOptions;

/*!
 @abstract Check if the application was launch after a click on a push notification
 
 @param silent if silent == YES, the push notification will be hidden (unless there is a pole/webview/redirection)
 @param launchOptions launchOptions received in the AppDelegate
 
 @see checkForNotificationsAtLaunching:
 */
- (void)checkForNotificationsAtLaunching:(NSDictionary *)launchOptions notificationIsSilent:(BOOL)silent;

/*!
 @abstract Manage the push notification reception
 
 @param userInfo userInfo received in the AppDelegate
 
 @discussion In the AppDelegate's didReceiveRemoteNotification method
 
 @see didReceiveRemoteNotificationAPPSPANEL:notificationIsSilent:
 */
- (void)didReceiveRemoteNotificationAPPSPANEL:(NSDictionary *)userInfo state:(UIApplicationState)state; 

/*!
 @abstract Manage the push notification reception
 
 @param silent if silent == YES, the push notification will be hidden (unless there is a pole/webview/redirection)
 @param userInfo userInfo received in the AppDelegate
 
 @see didReceiveRemoteNotificationAPPSPANEL:
 */
- (void)didReceiveRemoteNotificationAPPSPANEL:(NSDictionary *)userInfo notificationIsSilent:(BOOL)silent  state:(UIApplicationState)state;

/*!
 @name Ad
 */

/*!
 @abstract Use it to deactivate the SDK's ad at launching
 @param value if value == YES, the ad won't be automatically shown by the SDK
 
 @see showAd
 */
+ (void)desactivePubOnLaunching:(BOOL)value;

/*!
 @abstract Use it to show the ad at any moment
 
 @see desactivePubOnLaunching:
 */
+ (void)showAd;

/*!
 @name Stats
 */

/*!
 @abstract Use it to register action
 
 @param nameAction Name of your action
*/
+ (void)registerActionInAppsPanel:(NSString *)nameAction;

@end
