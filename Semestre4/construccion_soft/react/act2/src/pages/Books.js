import React from "react"
import { Button, Col, Container, Row } from "reactstrap";
import {connect} from "react-redux"
import Api from "../utils/Api";
import {setName, setFLastName, setMLastName, setEmail, setDate, addBook, deleteBooks } from "../store/actions"
import { withRouter } from "react-router-dom"


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
        Api.GET(
            "9780140328721",
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
                <div>
                    <p>{this.props.name} {this.props.fLastName} {this.props.mLastName}</p>
                    <p>{this.props.email}</p>
                    <p>{this.props.date}</p>
                    <Button onClick={this.logout}>Cerrar sesión</Button>
                </div>
                {/* search */}
                <div>
                    <input value={this.state.inputISBN} placeholder="Ingresa ISBN: " onChange={(e) => {this.setState({inputISBN: e.target.value})}}/>
                    <Button onClick={this.searchBook}>Buscar libro</Button>
                </div>

                {/* Search result */}
                {Object.keys(this.state.currentBook).length !== 0 && 
                    <div>
                        <p>Hola</p>
                        <h2>{this.state.currentBook.title}</h2>
                        <Button onClick={this.addBook}>Add to favorites</Button>
                    </div>
                }
                
                
                {/* Books */}
                {this.props.books.length !== 0 &&
                    <div>
                        <Row>
                            {this.props.books.map((book) => (
                                <Col>
                                    <h2>{book.title}</h2>
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