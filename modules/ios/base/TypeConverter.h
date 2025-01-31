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

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "MacroDefines.h"

#include <string>
#include <unordered_map>

NS_ASSUME_NONNULL_BEGIN


HP_EXTERN NSDictionary<NSString *, NSString *> *StringUnorderedMapToNSDictionary(const std::unordered_map<std::string, std::string> &);

std::unordered_map<std::string, std::string> NSDictionaryToStringUnorderedMap(NSDictionary<NSString *, NSString *> *dictionary);

HP_EXTERN NSURLResponse *ResponseMapToURLResponse(NSURL *url, const std::unordered_map<std::string, std::string> &headerMap, size_t contentsLength);

NS_ASSUME_NONNULL_END
