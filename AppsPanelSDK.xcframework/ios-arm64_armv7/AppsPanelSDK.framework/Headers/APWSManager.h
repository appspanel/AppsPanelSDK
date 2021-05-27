//
//  APWSManager.h
//  AppsPanelSDKV4
//
//  Created by Allan bouvard on 28/02/2014.
//  Copyright (c) 2014 Apps-Panel. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AppsPanel.h"

/*!
 *  @brief Enum for setting up log output level.
 *  @since 4.2.0
 */
typedef NS_ENUM(NSUInteger, APWSErrorType) {
    /*! @abstract An error happen on the WS (missing parameters, ...) */
    APWSErrorTypeUnknown,
    /*! @abstract The APWSManager failed because the device is not connected to internet (or the request timeout) */
	APWSErrorTypeNoConnection,
};

/**
 APWSError helps you to understand the issue that occured in your APWSManager
 @see APWSManager
 */
@interface APWSError : NSObject
/*!
 @abstract The message sent by the throw_exception on server side
 */
@property (nonatomic, strong) NSString *message;

/*!
 @abstract Error type
 */
@property (nonatomic, readwrite) APWSErrorType errorType;

/*
 @abstract The error code sent by the throw_exception on server side
 */
@property (nonatomic, readwrite) int code;

/*
 @abstract If something went wrong on the NSURLSession
 */
@property (nonatomic, strong) NSError *error;

/*
 @abstract If silent is false, the error will be prompted to user automacically
 */
@property (nonatomic, assign, getter=isSilent) BOOL silent;


@end

/*
 * Delegate APWSManagerDelegate
 */
@protocol APWSManagerDelegate;

/**
 APWSManager allows you to download data from AppsPanel webservices.
 */
@interface APWSManager : NSObject

/*!
 @abstract
 The delegate will receive the webservice's data

 @see APWSManagerDelegate
 */
#if __has_feature(objc_arc_weak)
@property (weak) id<APWSManagerDelegate> delegate;
#elif __has_feature(objc_arc)
@property (unsafe_unretained) id<APWSManagerDelegate> delegate;
#else
@property (assign) id<APWSManagerDelegate> delegate;
#endif

/*!
 @abstract
 The current request of the APWSManager 
 @discussion
 Will be instantiate after start
 
 @see start
 */
@property (nonatomic, strong) NSMutableURLRequest *theRequest;

/*!
 @abstract
 Use it to identify the APWSManager
 */
@property (nonatomic, readwrite) int tag;

/*!
 @abstract
 Result of the Webservice
 
 @discussion
 May be not null after apwsFailedDownload if there is cache on the request
 */
@property (nonatomic, strong) id result;

/*!
 @abstract
 apwsError != nil if there was an issue with the WebService
 
 @discussion
 apwsError will be nil only after apwsFailedDownload is called
 
 @see dateLastCache
*/
@property (nonatomic, strong) APWSError *apwsError;

/*!
 @abstract
 Use it to send file (multipart/form-data)
 
 @discussion
 NSArray of NSDictionnary (expected key "Name" (NSString *),  "FileName" (NSString *) and "Data" (NSData *) optional ContentType (NSString *))
 */
@property (nonatomic, strong) NSArray *listFiles;


/**
@abstract
Sets if the call needs a user token. If set to YES, the token will is added automatically in the right place.
 */
@property (nonatomic, assign) BOOL needsToken;

/*!
@abstract
NSDictionary of data to add to the JSON Web Token 
 */
@property (nonatomic, strong) NSDictionary *secureData;

/*!
 @abstract
 Use it to link an id that you wan't to use later
 */
@property (nonatomic, strong) id userInfos;

// If TRUE la request sera gardée en mémoire jusqu'au succès et pourra être réexécutée ultérieurement
// Lors d'une réexécution après un Bug (typiquement, pas de net au moment de l'action), le delegate ne sera pas rappelé !
@property (nonatomic, readwrite) BOOL forceRetry;
// Temps en secondes après lequel forceRetry timeout ([[NSDate date] dateByAddingTimeInterval:mustBeDoneTimeout]) - Par defaut il n'y a pas de timeout
@property (nonatomic, readwrite) NSInteger forceRetryTimeout;

/*!
 @name Initialization
 */
- (id)initWithRequest:(NSMutableURLRequest *)request delegate:(id)del andTag:(int)aTag;

/*!
 @name Initialization V3
 */

/*!
 @abstract
 Create an APWSManager object
 
 @discussion
 Use it only on V3 WS architecture
 
 @param action Name of the WS - eg : getDetails
 @param del The APWSManagerDelegate for the APWSManager object
 @param dictionnary List of key/value to send in GET
 @param aTag The tag to identify the APWSManager object
 
 @see start
 */
- (id)initWithAction:(NSString *)action delegate:(id)del WithGet:(NSDictionary *)dictionnary andTag:(int)aTag;

/*!
 @abstract
 Create an APWSManager object
 
 @discussion
 Use it only on V3 WS architecture
 
 @param action Name of the WS - eg : getDetails
 @param del The APWSManagerDelegate for the APWSManager object
 @param dictionnary List of key/value to send in GET
 @param aTag The tag to identify the APWSManager object
 @param isHtml If the WS return only HTML, should be set to TRUE
 
 @see start
 */
- (id)initWithAction:(NSString *)action delegate:(id)del WithGet:(NSDictionary *)dictionnary andTag:(int)aTag isHTMLType:(BOOL)isHtml;

/*!
 @abstract
 Create an APWSManager object
 
 @discussion
 Use it only on V3 WS architecture
 
 @param action Name of the WS - eg : getDetails
 @param del The APWSManagerDelegate for the APWSManager object
 @param dictionnary List of key/value to send in GET
 @param postDictionnary List of key/value to send in POST
 @param aTag The tag to identify the APWSManager object
 
 @see start
 */
- (id)initWithAction:(NSString *)action delegate:(id)del WithGet:(NSDictionary *)dictionnary andPost:(NSDictionary *)postDictionnary andTag:(int)aTag;

/*!
 @name Initialization V4 - REST
 */

/*!
 @abstract
 Create an APWSManager object
 
 @discussion
 Use it only on V4 WS architecture
 
 @param action Name of the WS - eg : user/{id_user}
 @param del The APWSManagerDelegate for the APWSManager object
 @param dictionnary List of key/value to send in GET
 @param aTag The tag to identify the APWSManager object
 
 @see start
 */
- (id)initWithRest:(NSString *)action delegate:(id <APWSManagerDelegate>)del WithGet:(NSDictionary *)dictionnary andTag:(int)aTag;

/*!
 @abstract
 Create an APWSManager object
 
 @discussion
 Use it only on V4 WS architecture
 
 @param action Name of the WS - eg : user/{id_user}
 @param del The APWSManagerDelegate for the APWSManager object
 @param dictionnary List of key/value to send in GET
 @param postDictionnary List of key/value to send in POST
 @param aTag The tag to identify the APWSManager object
 
 @see start
 */
- (id)initWithRest:(NSString *)action delegate:(id <APWSManagerDelegate>)del WithGet:(NSDictionary *)dictionnary andPost:(NSDictionary *)postDictionnary andTag:(int)aTag;

/*!
 @abstract
 Create an APWSManager object
 
 @discussion
 Use it only on V4 WS architecture
 
 @param action Name of the WS - eg : user/{id_user}
 @param del The APWSManagerDelegate for the APWSManager object
 @param dictionnary List of key/value to send in GET
 @param putDictionnary List of key/value to send in PUT
 @param aTag The tag to identify the APWSManager object
 
 @see start
 */
- (id)initWithRest:(NSString *)action delegate:(id <APWSManagerDelegate>)del WithGet:(NSDictionary *)dictionnary andPut:(NSDictionary *)putDictionnary andTag:(int)aTag;

/*!
 @abstract
 Create an APWSManager object
 
 @discussion
 Use it only on V4 WS architecture
 
 @param action Name of the WS - eg : user/{id_user}
 @param del The APWSManagerDelegate for the APWSManager object
 @param dictionnary List of key/value to send in GET
 @param patchDictionnary List of key/value to send in PATCH
 @param aTag The tag to identify the APWSManager object
 
 @see start
 */
- (id)initWithRest:(NSString *)action delegate:(id <APWSManagerDelegate>)del WithGet:(NSDictionary *)dictionnary andPatch:(NSDictionary *)patchDictionnary andTag:(int)aTag;

/*!
 @abstract
 Create an APWSManager object
 
 @discussion
 Use it only on V4 WS architecture
 
 @param action Name of the WS - eg : user/{id_user}
 @param del The APWSManagerDelegate for the APWSManager object
 @param dictionnary List of key/value to send in GET
 @param deleteDictionnary List of key/value to send in DELETE
 @param aTag The tag to identify the APWSManager object
 
 @see start
 */
- (id)initWithRest:(NSString *)action delegate:(id <APWSManagerDelegate>)del WithGet:(NSDictionary *)dictionnary andDelete:(NSDictionary *)deleteDictionnary andTag:(int)aTag;

/**
 Sets the security level for a designated WS call

 @param mode The security mode choosen
 @param randomizeKey A boolean indicating wether a random key should be used for this call
 */
- (void)securityModeForCall:(APSecurityMode)mode randomizeKey:(BOOL)randomizeKey;
/*!
 @abstract
 Call the webservice
 
 @discussion
 If an internet connection isn't available will call apwsFailedDownload
 
 @see cancel
 @see APWSManagerDelegate
 */
- (void)start;

/*!
 @abstract
 Cancel the current NSURLSessionDataTask
 
 @see start
 */
- (void)cancel;

/*!
 @name Request
 */

/*!
 @abstract Return the request
 
 @discussion
 Can be called before start
 
 @see theRequest
 */
- (NSMutableURLRequest *)getTheRequest;

/*!
 @name Request V3
 */

/*!
 @abstract
 Return a preformatted NSMutableURLRequest
 
 @discussion
 Use it only on V3 WS architecture
 
 @param action Name of the WS - eg : getDetails
 @param dictionnary List of key/value to send in GET
 @param postDictionnary List of key/value to send in POST
 */
+ (NSMutableURLRequest *)getRequestForAction:(NSString *)action WithGet:(NSDictionary *)dictionnary andPost:(NSDictionary *)postDictionnary;

/*!
 @abstract
 Return a preformatted NSMutableURLRequest
 
 @discussion
 Use it only on V3 WS architecture
 
 @param action Name of the WS - eg : getDetails
 @param dictionnary List of key/value to send in GET
 */
+ (NSMutableURLRequest *)getRequestForAction:(NSString *)action WithGet:(NSDictionary *)dictionnary;

/*!
 @name Request V4 - REST
 */
/*!
 @abstract
 Return a preformatted NSMutableURLRequest
 
 @discussion
 Use it only on V4 WS architecture
 
 @param action Name of the WS - eg : user/{id_user}
 @param dictionnary List of key/value to send in GET
 @param postDictionnary List of key/value to send in POST
 */
+ (NSMutableURLRequest *)getRequestForRest:(NSString *)action WithGet:(NSDictionary *)dictionnary andPost:(NSDictionary *)postDictionnary;

/*!
 @abstract
 Return a preformatted NSMutableURLRequest
 
 @discussion
 Use it only on V4 WS architecture
 
 @param action Name of the WS - eg : user/{id_user}
 @param dictionnary List of key/value to send in GET
 @param putDictionnary List of key/value to send in PUT
 */
+ (NSMutableURLRequest *)getRequestForRest:(NSString *)action WithGet:(NSDictionary *)dictionnary andPut:(NSDictionary *)putDictionnary;

/*!
 @abstract
 Return a preformatted NSMutableURLRequest
 
 @discussion
 Use it only on V4 WS architecture
 
 @param action Name of the WS - eg : user/{id_user}
 @param dictionnary List of key/value to send in GET
 @param patchDictionnary List of key/value to send in PATCH
 */
+ (NSMutableURLRequest *)getRequestForRest:(NSString *)action WithGet:(NSDictionary *)dictionnary andPatch:(NSDictionary *)patchDictionnary;

/*!
 @abstract
 Return a preformatted NSMutableURLRequest
 
 @discussion
 Use it only on V4 WS architecture
 
 @param action Name of the WS - eg : user/{id_user}
 @param dictionnary List of key/value to send in GET
 @param deleteDictionnary List of key/value to send in DELETE
 */
+ (NSMutableURLRequest *)getRequestForRest:(NSString *)action WithGet:(NSDictionary *)dictionnary andDelete:(NSDictionary *)deleteDictionnary;

/*!
 @abstract
 Return a preformatted NSMutableURLRequest
 
 @discussion
 Use it only on V4 WS architecture
 
 @param action Name of the WS - eg : user/{id_user}
 @param dictionnary List of key/value to send in GET
 */
+ (NSMutableURLRequest *)getRequestForRest:(NSString *)action WithGet:(NSDictionary *)dictionnary;

@end

/*!
 * Delegate APWSManagerDelegate
 */
@protocol APWSManagerDelegate <NSObject>
@required

/*!
 @abstract Called after the request Failed
 
 @param apws The APWSManager that has finished to do is job
 
 @see apwsFinishedDownload:
 */
- (void)apwsFailedDownload:(APWSManager *)apws;

/*!
 @abstract Called after the request succeeded
 
 @param apws The APWSManager that has failed to do is job
 
 @see apwsFailedDownload:
 */
- (void)apwsFinishedDownload:(APWSManager *)apws;

@optional

/*!
 @abstract Sent periodically to notify the delegate of upload progress
 
 @param apws The APWSManager that is doing is job
 @param bytesSent The bytes sent in the last package
 @param totalBytesSent The total of bytes sent this the beginning
 @param totalBytesExpectedToSend The total of bytes that the APWSManager object is supposed to send
 */
- (void)apwsManager:(APWSManager *)apws didSendBodyData:(int64_t)bytesSent totalBytesSent:(int64_t)totalBytesSent totalBytesExpectedToSend:(int64_t)totalBytesExpectedToSend;
@end
