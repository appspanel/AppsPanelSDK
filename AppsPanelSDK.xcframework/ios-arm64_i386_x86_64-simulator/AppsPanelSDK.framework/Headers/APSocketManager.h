//
//  APSocketManager.h
//  AppsPanelSDKV4
//
//  Created by Allan bouvard on 29/11/2014.
//  Copyright (c) 2014 Apps-Panel. All rights reserved.
//

#define APSocketManagerConnexionDidReceiveData @"APSocketManagerConnexionDidReceiveData"
#define APSocketManagerConnexionDidSuccess @"APSocketManagerConnexionDidSuccess"

@protocol APSocketManagerDelegate, APSocketManagerConnexionDelegate;

/**
 @abstract APSocketManager allow you to connect your application to your tcp server
 */
@interface APSocketManager : NSObject
#if __has_feature(objc_arc_weak)
@property (weak) id<APSocketManagerConnexionDelegate> delegate;
#elif __has_feature(objc_arc)
@property (unsafe_unretained) id<APSocketManagerConnexionDelegate> delegate;
#else
@property (assign) id<APSocketManagerConnexionDelegate> delegate;
#endif

/*!
 @abstract The inputStream can be used to check the current NSStreamStatus
 */
@property (nonatomic, readonly) NSInputStream *inputStream;

/*
 @name Singleton
 */

/*!
 @abstract Singleton instance of APSocketManager
 */
+ (APSocketManager *)sharedInstance;

/*!
 @abstract Setup the singleton connexion to the server
 
 @param host The address of the server (usually [YOUR_APPLICATION].socket.apnl.ws)
 @param port The port that the connexion will use (eg 1337)

 @discussion It will create a read and a write stream with CFStreamCreatePairWithSocketToHost
 */
+ (void)setup:(NSString *)host port:(UInt32)port;

/*!
 @abstract Send a message on the write stream of the singleton connexion
 
 @param action Name of the action to call
 @param param NSDictionnary to send with the action
 @param delegate APSocketManagerDelegate
 */
+ (void)sendAction:(NSString *)action withParam:(NSDictionary *)param delegate:(id<APSocketManagerDelegate>)delegate;

/*!
 @abstract Close the streams
 */
+ (void)stop;

/*
 @name Secundary socket
 */

/*!
 @abstract Setup a connexion to the server
 
 @param host The address of the server (usually [YOUR_APPLICATION].socket.apnl.ws)
 @param port The port that the connexion will use (eg 1337)
 
 @discussion
 It will create a read and a write stream with CFStreamCreatePairWithSocketToHost
 */
- (void)setup:(NSString *)host port:(UInt32)port;

/*!
 @abstract Send a message on the write stream of the connexion
 
 @param action Name of the action to call
 @param param NSDictionnary to send with the action
 @param delegate APSocketManagerDelegate
 
 @see #sendAction:withParam:delegate:
 */
- (void)sendAction:(NSString *)action withParam:(NSDictionary *)param delegate:(id<APSocketManagerDelegate>)delegate;

/*!
 @abstract Close the streams
 */
- (void)stop;
@end

/**
 * Delegate APSocketManagerConnexionDelegate
 */
@protocol APSocketManagerConnexionDelegate <NSObject>

/*!
 @abstract Called after the connexion Failed
 
 @param result Will always be nil
 */
- (void)socketConnexionFailed:(NSDictionary *)result;

/*!
 @abstract Called after the connexion Closed
 
 @param result Will always be nil
 */
- (void)socketConnexionDidClose:(NSDictionary *)result;

/*!
 @abstract Called after the connexion Succeed
 
 @param result Will always be nil
 */
- (void)socketConnexionSuccess:(NSDictionary *)result;

/*!
 @abstract Called after the server sent data
 
 @param result Data received from the server
 */
- (void)socketConnexionReceivedData:(NSDictionary *)result;

@end

/** 
 * Delegate APSocketManager
 */
@protocol APSocketManagerDelegate <NSObject>

/*!
 @abstract Called after the request Failed
 
 @param result Will always be nil
 
 @bug Should never be called
 */
- (void)socketFailedDownload:(NSDictionary *)result;

/*!
 @abstract Called after the request Finish
 
 @param result Return the sended_action and the result (response from the server)
 */
- (void)socketFinishedDownload:(NSDictionary *)result;

@end