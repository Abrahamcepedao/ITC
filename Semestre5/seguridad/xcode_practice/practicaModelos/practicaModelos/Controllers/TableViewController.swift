//
//  TableViewController.swift
//  practicaModelos
//
//  Created by Abraham Cepeda Oseguera on 23/08/21.
//

import UIKit

class TableViewController: UIViewController, UITableViewDelegate, UITableViewDataSource {
    
    
    var  randomUsers: [RandomUser]  = []

    @IBOutlet weak var userTableView: UITableView!
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        
        userTableView.delegate = self
        userTableView.dataSource = self
        
        let nib = UINib(nibName: "UserTableViewCell", bundle: nil)
        userTableView.register(nib, forCellReuseIdentifier: "userCell")
        fetchData()

        // Do any additional setup after loading the view.
    }
    
    func fetchData(){
        NetworkManager.getExternalData(fileLocation: "https://randomuser.me/api/?results=10", method:  .get, parameters: nil, stringParameters: nil) { (event: RandomUserRequest?, error) in
            if error != nil {
                print(error!)
            } else{
                if let randomUserRequest = event {
                    self.randomUsers = randomUserRequest.results
                    self.userTableView.reloadData()
                }
            }
        }
    }
    
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        randomUsers.count
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "userCell") as! UserTableViewCell
        
        let user = randomUsers[indexPath.row]
        
        let name = "\(user.name.title). \(user.name.first) \(user.name.last) "
        
        cell.userLbl.text = name
        cell.genderLbl?.text =  user.gender
        
        let url = URL(string: user.picture.medium)!
        cell.userImg.downloaded(from: url)
        
        return  cell
    }
    
}
