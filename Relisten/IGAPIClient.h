//
//  IGAPIClient.h
//  iguana
//
//  Created by Alec Gorge on 3/2/14.
//  Copyright (c) 2014 Alec Gorge. All rights reserved.
//

#import <AFHTTPSessionManager.h>

#import "IGYear.h"
#import "IGShow.h"
#import "IGVenue.h"
#import "IGArtist.h"
#import "IGUser.h"
#import "IGPlaylist.h"

@interface IGAPIClient : AFHTTPSessionManager

+ (instancetype)sharedInstance;

@property (nonatomic, strong) IGArtist *artist;

// an array of IGYear's
- (void)years:(void (^)(NSArray *))success;

- (void)artists:(void (^)(NSArray *))success;

- (void)playlists:(void (^)(NSArray *))success;

- (void)year:(NSUInteger)year success:(void (^)(IGYear *))success;

// an array of IGShow's
- (void)showsOn:(NSString *)displayDate success:(void (^)(NSArray *))success;

- (void)randomShowForArtist:(void (^)(NSArray *))success;

// venues
- (void)venuesForArtist:(void (^)(NSArray *))success;

- (void)venue:(IGVenue *)venue success:(void (^)(IGVenue *))success;

- (void)topShowsForArtist:(void (^)(NSArray *))success;

@end
