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

#import "THTimelineItemViewModel.h"
#import "THFunctions.h"

@implementation THTimelineItemViewModel

+ (id)modelWithTimelineItem:(THTimelineItem *)timelineItem {
	return [[self alloc] initWithTimelineItem:timelineItem];
}

- (id)initWithTimelineItem:(THTimelineItem *)timelineItem {
	self = [super init];
	if (self) {
        // 赋值属性，计算其占用轨道的最大宽度
		_timelineItem = timelineItem;
		CMTimeRange maxTimeRange = CMTimeRangeMake(kCMTimeZero, timelineItem.timeRange.duration); // 最大时间范围从0开始
		_maxWidthInTimeline = THGetWidthForTimeRange(maxTimeRange, THTimelineWidth / THTimelineSeconds);
	}
	return self;
}

- (CGFloat)widthInTimeline {
	if (_widthInTimeline == 0.0f) {
		_widthInTimeline = THGetWidthForTimeRange(self.timelineItem.timeRange, THTimelineWidth / THTimelineSeconds);
	}
	return _widthInTimeline;
}

- (void)updateTimelineItem {
	
	// Only care about position if user explicitly positioned media item.
	// This can only happen on the title and commentary tracks.
	if (self.positionInTimeline.x > 0.0f) {
		CMTime startTime = THGetTimeForOrigin(self.positionInTimeline.x, THTimelineWidth / THTimelineSeconds);
		self.timelineItem.startTimeInTimeline = startTime;
	}
	
	self.timelineItem.timeRange = THGetTimeRangeForWidth(self.widthInTimeline, THTimelineWidth / THTimelineSeconds);
}

@end
