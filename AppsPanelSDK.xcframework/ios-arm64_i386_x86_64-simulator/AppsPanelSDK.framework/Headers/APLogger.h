//
//  APLogger.h
//  AppsPanelSDKV3
//
//  Created by Arnaud Olivier on 04/07/2017.
//  Copyright © 2017 Apps-Panel. All rights reserved.
//

extern BOOL myDebugLight, myDebugNone, myDebugFull, myDebugWS;
#define APLog(fmt, ...) if (myDebugLight || myDebugFull) NSLog((@"%s " fmt), __PRETTY_FUNCTION__, ##__VA_ARGS__);
#define APLightLog(fmt, ...) if (myDebugLight || myDebugFull) NSLog((@"%s " fmt), __PRETTY_FUNCTION__, ##__VA_ARGS__);
#define APFullLog(fmt, ...) if (myDebugFull) NSLog((@"%s " fmt), __PRETTY_FUNCTION__, ##__VA_ARGS__);
#define APWSLog(fmt, ...) if (myDebugFull || (myDebugWS && ![self isKindOfClass:[APWSSDKManager class]])) NSLog((@"%s " fmt), __PRETTY_FUNCTION__, ##__VA_ARGS__);
