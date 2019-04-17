#import "ARenderView.h"
#import "AGame.h"

#import <Foundation/Foundation.h>

//==============================================================================

@interface ARenderView ()<NSGestureRecognizerDelegate>
    @property (nonatomic, assign) NSTimeInterval animationInterval;
    @property (nonatomic, strong) NSTimer *animationTimer;
    @property (nonatomic, assign) spcTGame::AGame *gameEngine;
@end

//==============================================================================

@implementation ARenderView

//==============================================================================

#pragma mark - View lifecycle -

//==============================================================================

- (instancetype)initWithFrame:(NSRect)frame pixelFormat:(NSOpenGLPixelFormat*)format
{
    self = [super initWithFrame:frame pixelFormat:format];
    if (self == nil)
    {
        return nil;
    }
    
    self.openGLContext.view = self;

    self.animationInterval = 1.0f / 60.0f;
    
    self.gameEngine = new spcTGame::AGame();
    self.gameEngine->updateScreenSize(CGRectGetWidth(self.bounds), CGRectGetHeight(self.bounds));
    self.gameEngine->startGame();

    [self startAnimation];
    
    return self;
}

//==============================================================================

- (void)dealloc
{
    delete _gameEngine;
}

//==============================================================================

- (void)viewDidEndLiveResize
{
	[self stopAnimation];
    self.gameEngine->updateScreenSize(CGRectGetWidth(self.bounds), CGRectGetHeight(self.bounds));
    [self startAnimation];
}

//==============================================================================

#pragma mark - Animation timer -

//==============================================================================

- (void)animationTimerHandler
{
    self.gameEngine->processGameCycle();
    [self.openGLContext flushBuffer];
}

//==============================================================================

- (void)startAnimation
{
    self.animationTimer = [NSTimer scheduledTimerWithTimeInterval: self.animationInterval
                                                           target: self
                                                         selector: @selector(animationTimerHandler)
                                                         userInfo: nil
                                                          repeats: YES];
}

//==============================================================================

- (void)stopAnimation
{
	[self.animationTimer invalidate];
	self.animationTimer = nil;
}

//==============================================================================

#pragma mark - Key events -

//==============================================================================

- (BOOL)acceptsFirstResponder
{
    return YES;
}

//==============================================================================

- (void)keyDown:(NSEvent *)theEvent
{
    self.gameEngine->processKeyboardEvent(theEvent.keyCode);
}

//==============================================================================

- (void)mouseUp:(NSEvent *)event
{
    self.gameEngine->processMouseEvent(spcTGame::APoint2D([event locationInWindow].x, [event locationInWindow].y));
}

//==============================================================================

@end
