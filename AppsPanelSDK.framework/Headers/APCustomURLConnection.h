//
//  APCustomURLConnection.m
//  AppsPanel
//
//  Copyright (c) 2012 Nomeo. All rights reserved.
//

/**
 * @discussion Deprecated in iOS 9.0
 * @discussion Do not use anymore !
 */
@interface APCustomURLConnection : NSURLConnection

@property (nonatomic, assign) int tag;
@property (nonatomic, retain) NSMutableData *receivedData;

- (id)initWithRequest:(NSURLRequest *)request delegate:(id)delegate startImmediately:(BOOL)startImmediately tag:(int)_tag;
- (id)initWithURLString:(NSString *)urlString withTimeOut:(NSTimeInterval)time delegate:(id)delegate startImmediately:(BOOL)startImmediately tag:(int)_tag;

@end