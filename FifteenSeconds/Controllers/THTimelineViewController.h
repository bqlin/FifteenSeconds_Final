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

#import "THTimeline.h"
#import "THMediaItem.h"
#import "THTimelineItem.h"
#import "THTimelineLayout.h"
#import "THTimeline.h"

@interface THTimelineViewController : UIViewController

/// 全局进度开关
@property (nonatomic) BOOL transitionsEnabled;
/// 全局音量淡入淡出开关
@property (nonatomic) BOOL volumeFadesEnabled;
/// 全局闪避旁白开关
@property (nonatomic) BOOL duckingEnabled;
/// 启动标题
@property (nonatomic) BOOL titlesEnabled;

/// 内嵌的集合视图
@property (weak, nonatomic) IBOutlet UICollectionView *collectionView;

/// 添加时间线模型到指定轨道
- (void)addTimelineItem:(THTimelineItem *)item toTrack:(THTrack)track;
- (void)clearTimeline;
- (THTimeline *)currentTimeline;
- (void)updateMusicTrackVolumeAutomation;
- (void)synchronizePlayheadWithPlayerItem:(AVPlayerItem *)playerItem;
- (void)addTitleItems;

@end
