//
//  AppDelegate.swift
//  doom
//
//  Created by cipher on 11.12.2023.
//

import Cocoa
import MetalKit

@main
class AppDelegate: NSObject, NSApplicationDelegate {

    private weak var window: NSWindow?
    
    func applicationDidFinishLaunching(_ aNotification: Notification) {
        window = createWindow()
//        window?.toggleFullScreen(nil);
        NSApp.mainMenu = createMenubar()
    }

    func applicationWillTerminate(_ aNotification: Notification) {
        // Insert code here to tear down your application
    }

    //  MARK: - Routine -
    
    private func createWindow() -> NSWindow {
        let screenSize = NSMakeSize(NSScreen.main?.frame.width ?? 0, NSScreen.main?.frame.height ?? 0)
        let windowSize = NSMakeSize(800, 600)
        let windowFrame = NSMakeRect(screenSize.width / 2 - windowSize.width / 2,
                                     screenSize.height / 2 - windowSize.height / 2,
                                     windowSize.width,
                                     windowSize.height)
        let newWindow = NSWindow(contentRect: windowFrame,
                                 styleMask: [.miniaturizable, .titled, .closable, .resizable],
                                 backing: .buffered,
                                 defer: false)
        newWindow.title = ProcessInfo.processInfo.processName
        newWindow.makeKeyAndOrderFront(self)
        
        let metalView = MTKView(frame: NSMakeRect(0, 0, windowSize.width, windowSize.height))
        metalView.device = MTLCreateSystemDefaultDevice()
        
        let viewController = ViewController()
        viewController.view = metalView
        metalView.delegate = viewController
        newWindow.contentViewController = viewController
        newWindow.makeFirstResponder(viewController)
        
        return newWindow
    }

    private func createMenubar() -> NSMenu {
        let quitItem = NSMenuItem(title: "Quit \(ProcessInfo.processInfo.processName)",
                                      action: #selector(terminate),
                                      keyEquivalent: "q")

        let applicationMenu = NSMenu()
        applicationMenu.addItem(quitItem)
        let applicationMenuItem = NSMenuItem()
        applicationMenuItem.submenu = applicationMenu

        let menubar = NSMenu()
        menubar.addItem(applicationMenuItem)
        
        return menubar
    }
    
    @objc
    private func terminate() {
        NSApp.terminate(self)
    }
    
}
