//
//  Application.swift
//  doom
//
//  Created by cipher on 11.12.2023.
//

import Cocoa

class Application: NSApplication {
    
    let applicationDelegate = AppDelegate()
    
    override init() {
        super.init()
        
        delegate = applicationDelegate
    }
    
    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
}
