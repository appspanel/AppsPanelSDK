//
//  NSData+Zip.h
//  AppsPanelSDKV4
//
//  Created by Allan bouvard on 01/04/2014.
//  Copyright (c) 2014 Apps-Panel. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 An NSData categorie that allow you to compress (.gzip) any data
 */
@interface NSData (Zip)

/*!
 @abstract Inflate
 
 @return self with inflate data
 
 @see zipDeflate
 */
- (NSData *)zipInflate;

/*!
 @abstract Deflate
 
 @return self with deflate data
 
 @see zipInflate
 */
- (NSData *)zipDeflate;

@end