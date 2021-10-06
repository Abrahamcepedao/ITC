//
//  Track.swift
//  Multimedia
//
//  Created by Abraham Cepeda Oseguera on 24/09/21.
//

import Foundation

struct Track: Codable {
    let type: TrackType
    let id: String
    let index, disc: Int
    let href: String
    let playbackSeconds: Int
    let explicit, isStreamable: Bool
    let name, isrc, shortcut: String
    //let blurbs: [Any?]
    let artistID, artistName, albumName: String
    let albumID: String
    let contributors: Contributors
    let links: Links
    let previewURL: String
}

struct TrackType: Codable  {
    
}

struct Contributors: Codable  {
    
}

struct Links: Codable  {
    
}
