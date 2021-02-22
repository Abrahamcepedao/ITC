import { ADD_BOOK, DELETE_BOOKS } from "./actionType";

export const addBook = (book) => {
    return {
        type: ADD_BOOK,
        data: book
    }
};

export const deleteBooks = () => {
    return {
        type: DELETE_BOOKS
    }
}

