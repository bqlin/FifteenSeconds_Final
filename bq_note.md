## 添加分类
AVComposition
	添加写入文件方法；
AVPlayerItem
	添加 AVSynchronizedLayer *syncLayer 属性；
	添加时长可用方法；
	添加静音方法；
NSString
UIAlertView
UIColor
UIView


## THAudioPickerViewController
点击THAudioItemTableViewCell 的 previewButton 会发生什么？
	中间层对象调用预览方法；

哪些地方发出过 THPlaybackEndedNotification 通知，该通知发出时做了什么操作？

使用到的模型：
- THAudioItem
	+ THMediaItem 的子类
- THMediaItem
	+ THTimelineItem 的子类
	+ 描述媒体的对象


## THTimelineViewController

通知
- THTransitionsEnabledStateChangeNotification
- THTransitionsEnabledStateChangeNotification
- THVolumeDuckingEnabledStateChangeNotification
- THShowTitlesEnabledStateChangeNotification

dataSource.timelineItems 在哪里赋值？
 该数组的结构
  一层元素：THTimelineItemViewModel
  	二级元素：THTimelineItemViewModel的timelineItem属性，THTimelineItem

如何预览

```objective-c
#pragma mark - playbackMediator 协议实现
/// 载入媒体项，在创建`THVideoItem`对象时也会调用
- (void)loadMediaItem:(THMediaItem *)mediaItem {
	[self.playerViewController loadInitialPlayerItem:[mediaItem makePlayable]];
}

/// 预览媒体项，其他控制器主动调用预览
- (void)previewMediaItem:(THMediaItem *)mediaItem {
	[self.playerViewController playPlayerItem:[mediaItem makePlayable]];
}

/// 预览轨道
- (void)prepareTimelineForPlayback {
	THTimeline *timeline = self.timelineViewController.currentTimeline;
	id<THCompositionBuilder> builder = [self.factory builderForTimeline:timeline];
	id<THComposition> composition = [builder buildComposition];
    AVPlayerItem *playerItem = [composition makePlayable];
    [self.timelineViewController synchronizePlayheadWithPlayerItem:playerItem];
    // 播放
	[self.playerViewController playPlayerItem:playerItem];
}

/// 添加媒体到轨道
- (void)addMediaItem:(THMediaItem *)item toTimelineTrack:(THTrack)track {
	[self.timelineViewController addTimelineItem:item toTrack:track];
}

/// 停止播放
- (void)stopPlayback {
	[self.playerViewController stopPlayback];
}
```

```objective-c
/// THPlayerViewController 实现

- (void)loadInitialPlayerItem:(AVPlayerItem *)playerItem {
	dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_LOW, 0), ^{
		self.autoplayContent = NO;
		self.playerItem = playerItem;
		[self prepareToPlay];
	});
}

/// 预览
- (void)playPlayerItem:(AVPlayerItem *)playerItem {
	[self.titleView removeFromSuperview];
	self.autoplayContent = YES;
	self.player.rate = 0.0f;
	self.playerItem = playerItem;
    self.playButton.selected = YES;
	if (playerItem) {
		[self prepareToPlay];
	} else {
		NSLog(@"Player item is nil.  Nothing to play.");
	}
}

/// 主动点击播放
- (IBAction)play:(id)sender {
	UIButton *button = sender;
	if (self.player.rate == 1.0) {
		self.player.rate = 0.0f;
		button.selected = NO;
	} else {
		[self.playbackMediator prepareTimelineForPlayback];
		button.selected = YES;
	}
}
```