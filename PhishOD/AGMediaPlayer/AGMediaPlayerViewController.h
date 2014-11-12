//
//  AGMediaPlayerViewController.h
//  iguana
//
//  Created by Alec Gorge on 3/3/14.
//  Copyright (c) 2014 Alec Gorge. All rights reserved.
//

#import <UIKit/UIKit.h>

#import <StreamingKit/STKAudioPlayer.h>

#import "AGMediaItem.h"
#import "PTSHeatmap.h"

@interface AGMediaPlayerViewController : UIViewController<UITableViewDataSource, UITableViewDelegate, STKAudioPlayerDelegate, UIActionSheetDelegate>

+ (instancetype)sharedInstance;

@property (nonatomic, readonly) STKAudioPlayerState state;

// playing, buffering etc
@property (nonatomic, readonly) BOOL playing;
@property (nonatomic, readonly) BOOL buffering;
@property (strong, nonatomic) STKAudioPlayer *audioPlayer;

// an array of AGMediaItems
@property (nonatomic) NSMutableArray *playbackQueue;
@property (nonatomic, readonly) AGMediaItem *currentItem;
@property (nonatomic, readonly) AGMediaItem *nextItem;
@property (nonatomic, readonly) NSInteger nextIndex;

@property (nonatomic) NSInteger currentIndex;

- (void)replaceQueueWithItems:(NSArray *) queue startIndex:(NSInteger)index;
- (void)addItemsToQueue:(NSArray *)queue;

@property (nonatomic) BOOL shuffle;
@property (nonatomic) BOOL loop;
@property (nonatomic) float progress;
@property (nonatomic) NSTimeInterval elapsed;
@property (nonatomic, readonly) float duration;

- (void)forward;
- (void)play;
- (void)pause;
- (void)backward;
- (void)togglePlayPause;

- (void)redrawUICompletely;

@property (nonatomic) PTSHeatmap *heatmap;

@end
