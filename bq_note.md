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