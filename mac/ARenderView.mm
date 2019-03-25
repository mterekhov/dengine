#import "ARenderView.h"
#import "AGame.h"

#import <Foundation/Foundation.h>

//==============================================================================

@interface ARenderView ()
    @property (nonatomic, assign) NSTimeInterval animationInterval;
    @property (nonatomic, assign) NSTimeInterval animationStarted;
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
    
    self.gameEngine = new spcTGame::AGame();
    self.animationInterval = 1.0f / 60.0f;
    [self startAnimation];
    self.gameEngine->startGame();

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
    self.gameEngine->updateScreenSize(self.frame.size.width, self.frame.size.height);
    [self startAnimation];
}

//==============================================================================

#pragma mark - Animation timer -

//==============================================================================

- (void)animationTimerHandler
{
    self.gameEngine->processGameCycle();
    
    [[NSOpenGLContext currentContext] flushBuffer];
}

//==============================================================================

- (void)startAnimation
{
    self.animationTimer = [NSTimer scheduledTimerWithTimeInterval: self.animationInterval
                                                           target: self
                                                         selector: @selector(animationTimerHandler)
                                                         userInfo: nil
                                                          repeats: YES];
	self.animationStarted = [NSDate timeIntervalSinceReferenceDate];
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

@end
