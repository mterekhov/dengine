//
//  AOpenGLView.swift
//  game
//
//  Created by Michael on 22.03.2019.
//  Copyright © 2019 Michael. All rights reserved.
//

import Cocoa

class AOpenGLView : NSOpenGLView
{
    private var animationTimer = Timer();
    
    // MARK: - Animation Timer -
    
    private func fireAnimationTimer(interval:TimeInterval)
    {
        animationTimer = Timer.init(timeInterval: interval, repeats: true, block: { (timer) in
            self.renderGameFrame()
        })
    }
    
    private func killAnimationTimer()
    {
        animationTimer.invalidate()
        animationTimer = Timer();
    }
    
    private func setupAnimationInterval(interval:TimeInterval)
    {
        killAnimationTimer()
        fireAnimationTimer(interval: interval)
    }
    
    // MARK: - Public -
    
    override func viewDidEndLiveResize() {
        killAnimationTimer()
        
        
        
        fireAnimationTimer(interval: 1.0 / 60.0)
    }
    
    // MARK: - Routine -

    private func renderGameFrame()
    {
        
    }
    
}
