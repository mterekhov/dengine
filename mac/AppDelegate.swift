//
//  AppDelegate.swift
//  game
//
//  Created by Michael on 22.03.2019.
//  Copyright © 2019 Michael. All rights reserved.
//

import Cocoa

@NSApplicationMain
class AppDelegate: NSObject, NSApplicationDelegate
{

    @IBOutlet weak var window: NSWindow!

    func applicationDidFinishLaunching(_ aNotification: Notification)
    {
        let attrs = [
            UInt32(NSOpenGLPFANoRecovery),
            UInt32(NSOpenGLPFAColorSize),
            UInt32(32),
            UInt32(NSOpenGLPFADepthSize),
            UInt32(32),
            UInt32(NSOpenGLPFAMaximumPolicy),
            UInt32(NSOpenGLPFADoubleBuffer),
            UInt32(NSOpenGLPFAAccelerated),
            0
        ]
        
        let pixelFormat = NSOpenGLPixelFormat.init(attributes: attrs)
        let openGLView = AOpenGLView.init(frame: window.frame, pixelFormat: pixelFormat)
        window.contentView = openGLView
        window.makeFirstResponder(openGLView)
    }

}
