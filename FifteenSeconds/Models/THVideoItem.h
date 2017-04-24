//
//  MIT License
//
//  Copyright (c) 2014 Bob McCune http://bobmccune.com/
//  Copyright (c) 2014 TapHarmonic, LLC http://tapharmonic.com/
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.
//

#import "THMediaItem.h"
#import "THVideoTransition.h"

@interface THVideoItem : THMediaItem

/// 缩略图数组
@property (strong, nonatomic) NSArray *thumbnails;

+ (id)videoItemWithURL:(NSURL *)url;

/// 片段头过渡
@property (strong, nonatomic) THVideoTransition *startTransition;
/// 片段尾过渡
@property (strong, nonatomic) THVideoTransition *endTransition;

/// 视频播放时间区间，只有getter方法
@property (nonatomic, readonly) CMTimeRange playthroughTimeRange;
/// 开始过渡时间区间，只有getter方法
@property (nonatomic, readonly) CMTimeRange startTransitionTimeRange;
/// 结束过渡时区间，只有getter方法
@property (nonatomic, readonly) CMTimeRange endTransitionTimeRange;

@end
