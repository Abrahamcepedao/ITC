//
//  RandomUser.swift
//  practicaModelos
//
//  Created by Abraham Cepeda Oseguera on 19/08/21.
//

import Foundation


struct RandomUserRequest: Codable {
    let results: [RandomUser]
}

struct RandomUser: Codable {
    let gender: String
    let name: Name
    let picture: Picture
}


struct Name: Codable {
    let title: String
    let first: String
    let last: String
}

struct Picture: Codable {
    let medium: String
}
