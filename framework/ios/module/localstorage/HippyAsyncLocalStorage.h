/*!
 * iOS SDK
 *
 * Tencent is pleased to support the open source community by making
 * Hippy available.
 *
 * Copyright (C) 2019 THL A29 Limited, a Tencent company.
 * All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#import "HippyBridgeModule.h"
#import "HPInvalidating.h"

/**
 * A simple, asynchronous, persistent, key-value storage system designed as a
 * backend to the AsyncStorage JS module, which is modeled after LocalStorage.
 *
 * Current implementation stores small values in serialized dictionary and
 * larger values in separate files. Since we use a serial file queue
 * `RKFileQueue`, reading/writing from multiple threads should be perceived as
 * being atomic, unless someone bypasses the `HippyAsyncLocalStorage` API.
 *
 * Keys and values must always be strings or an error is returned.
 */
extern NSString *const HippyStorageDirectory;

extern NSUInteger HPLOCALSTORAGEIOTYPEREAD;

extern NSUInteger HPLOCALSTORAGEIOTYPEWRITE;

@interface HippyAsyncLocalStorage : NSObject <HippyBridgeModule, HPInvalidating>

@property (nonatomic, assign) BOOL clearOnInvalidate;

@property (nonatomic, readonly, getter=isValid) BOOL valid;

/**
 * Clear the HippyAsyncLocalStorage data from native code
 */
+ (void)clearAllData;

/**
 * Get storage directory for HippyAsyncLocalStorage
 * overwrite this function to return your customized directory
 *
 *@discussion default storage directory is #{your app sand box}/document/HippyAsyncLocalStorage_V1/#{module name}
 * @return storage directory for HippyAsyncLocalStorage
 */
- (NSString *)HippyGetStorageDirectory;

/**
 * Get maxium data read limit
 *
 * @discussion if data size exceed range, *handleDataSizeExceed* method will be invoked.Default is NSUIntegerMax
 * @return max read data size
 */
- (NSUInteger)maxReadDataSize;

/**
 * Get maxium data write limit
 *
 * @discussion if data size exceed range, *handleDataSizeExceed* method will be invoked.Default is NSUIntegerMax
 * @return max write data size
 */
- (NSUInteger)maxWriteDataSize;

/**
 * handle data size exceed range event
 *
 * @discussion default return YES and does nothing
 * @param IOType HPLOCALSTORAGEIOTYPEREAD or HPLOCALSTORAGEIOTYPEWRITE action
 * @param moduleName module which triggered this operation
 * @param length The amount of data that corresponds to this operation
 * @return Continue read or write if return YES
 */
- (BOOL)handleDataSizeExceedForIOType:(NSUInteger)IOType moduleName:(NSString *)moduleName key:(NSString *)key dataLength:(NSUInteger)length;

@end
