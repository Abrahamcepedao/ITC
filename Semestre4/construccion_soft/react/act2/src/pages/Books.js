import React from "react"
import { Button, Col, Container, Row } from "reactstrap";
import {connect} from "react-redux"
import Api from "../utils/Api";
import {setName, setFLastName, setMLastName, setEmail, setDate, addBook, deleteBooks } from "../store/actions"
import { withRouter } from "react-router-dom"

//Css
import "./Books.css"

//MaterialUI
import PersonRoundedIcon from '@material-ui/icons/PersonRounded';
import EmailRoundedIcon from '@material-ui/icons/EmailRounded';
import AccessibilityRoundedIcon from '@material-ui/icons/AccessibilityRounded';
import FavoriteRoundedIcon from '@material-ui/icons/FavoriteRounded';
import SearchRoundedIcon from '@material-ui/icons/SearchRounded';
import DoneOutlineRoundedIcon from '@material-ui/icons/DoneOutlineRounded';

class Books extends React.Component{

    constructor(props) {
        super(props);
        this.state = {
            currentBook: {},
            inputISBN: ""
        }
    }

    componentDidMount(){
        /* Api.GET(
            "9780140328721",
            (data)=>{
                this.setState({currentBook:data})
            }
        ) */
        if(Object.keys(this.state.currentBook).length !== 0){
            console.log("ok")
        } else{
            console.log("error")
        }

        console.log(this.state.currentBook)
        
    }



    searchBook = () => {
        //localStorage.setItem("ISBN", this.inputBook.current.getValue());
        //9780140328721
        //0914846922
        //5699611185
        Api.GET(
            this.state.inputISBN,
            (data)=>{
                this.setState({currentBook:data})
            }
        )
        console.log(this.state.currentBook)
    }

    addBook = () => {
        this.props.addBook(this.state.currentBook);
        console.log(this.props.books)
    }

    logout = () => {
        this.props.setName("")
        this.props.setFLastName("")
        this.props.setMLastName("")
        this.props.setEmail("")
        this.props.setDate("")
        localStorage.setItem("name", "")
        localStorage.setItem("fLastName", "")
        localStorage.setItem("mLastName", "")
        localStorage.setItem("email", "")
        localStorage.setItem("date", "")
        this.props.deleteBooks();
        this.props.history.push("/login")
    }

    render(){

        return (
            <Container>
                {/* Header with info */}
                <div style={{background: 'rgb(240,240,240)', marginTop: '50px', borderRadius: '25px', padding: '50px', marginBottom: '50px'}}>
                    <h2 style={{fontWeight: 'bold'}}>Personal information</h2>
                    <p><PersonRoundedIcon/> {this.props.name} {this.props.fLastName} {this.props.mLastName}</p>
                    <p><EmailRoundedIcon/> {this.props.email}</p>
                    <p><AccessibilityRoundedIcon/> {this.props.date}</p>
                    <Button className="button" color="danger" onClick={this.logout}>Logout</Button>
                </div>
                {/* search */}
                <div style={{background: 'rgb(240,240,240)', marginTop: '50px', borderRadius: '25px', padding: '50px', marginBottom: '50px'}}>
                    <h2 style={{fontWeight: 'bold', marginBottom: '30px'}}><SearchRoundedIcon style={{fontSize: '45px'}}/> Search book by ISBN</h2>
                    <input className="input" value={this.state.inputISBN} placeholder="Ingresa ISBN: " onChange={(e) => {this.setState({inputISBN: e.target.value})}}/>
                    <Button className="button" color="primary" onClick={this.searchBook}>Search book</Button>
                </div>

                {/* Search result */}
                {Object.keys(this.state.currentBook).length !== 0 && 
                    <div style={{background: 'rgb(240,240,240)', marginTop: '50px', borderRadius: '25px', padding: '50px', marginBottom: '50px'}}>
                        <h2 style={{fontWeight: 'bold', marginBottom: '30px'}}><DoneOutlineRoundedIcon style={{fontSize: '45px'}}/> Result of request</h2>
                        <div style={{background: 'rgb(255,255,255)', margin: 'auto', marginTop: '50px', borderRadius: '25px', padding: '20px', marginBottom: '50px', width: '300px'}}>
                            <h3>{this.state.currentBook.title}</h3>
                            <p><strong>Number of pages:</strong> {this.state.currentBook.number_of_pages}</p>
                            <p><strong>Published date:</strong> {this.state.currentBook.publish_date}</p>
                            {this.state.currentBook.publishers.map((item) => (
                                <p><strong>Publishers:</strong> {item}</p>
                            ))}
                            
                        </div>
                        <Button className="button" color="primary" onClick={this.addBook}>Add to favorites</Button>
                    </div>
                }
                
                
                {/* Books */}
                {this.props.books.length !== 0 &&
                    <div style={{background: 'rgb(240,240,240)', marginTop: '50px', borderRadius: '25px', padding: '50px', marginBottom: '50px'}}>
                        <h2 style={{fontWeight: 'bold'}}><FavoriteRoundedIcon style={{fontSize: '45px'}}/> Favorites</h2>
                        <Row>
                            {this.props.books.map((book) => (
                                <Col md={6}>
                                    <div style={{background: 'rgb(255,255,255)', margin: 'auto', marginTop: '50px', borderRadius: '25px', padding: '20px', marginBottom: '50px'}}>
                                        <h3>{book.title}</h3>
                                        <p><strong>Number of pages:</strong> {book.number_of_pages}</p>
                                        <p><strong>Published date:</strong> {book.publish_date}</p>
                                        {book.publishers.map((item) => (
                                            <p><strong>Publishers:</strong> {item}</p>
                                        ))}
                                        
                                    </div>
                                </Col>
                            ))}
                            
                        </Row>
                    </div>
                }
                
            </Container>
        )
    }

}

const mapStateToProps = (store) => {
    return {
        name: store.userState.name,
        fLastName: store.userState.fLastName,
        mLastName: store.userState.mLastName,
        email: store.userState.email,
        date: store.userState.date,
        books: store.booksState.books
    }
}

const mapDispatchToProps = {setName, setFLastName, setMLastName, setEmail, setDate, addBook, deleteBooks}

export default withRouter(connect(mapStateToProps, mapDispatchToProps)(Books));