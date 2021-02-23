import { ADD_BOOK, DELETE_BOOKS } from "./actionType";

export const addBook = (books) => {
    if(localStorage.getItem("books")){
        console.log([...JSON.parse(localStorage.getItem("books")), books]);
        localStorage.setItem("books", JSON.stringify([...JSON.parse(localStorage.getItem("books")), books]));
    } else{
        console.log("first")
        localStorage.setItem("books", JSON.stringify([books]));
    }
    
    return {
        type: ADD_BOOK,
        data: books
    }
};

export const deleteBooks = () => {
    localStorage.setItem("books", "[]");
    return {
        type: DELETE_BOOKS
    }
}

