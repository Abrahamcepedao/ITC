import { ADD_BOOK, DELETE_BOOKS } from "./actionType";

const INIT_STATE = {
    books: [],
}

const user = (state = INIT_STATE, action) => {
    switch(action.type){
        case ADD_BOOK: 
            return {
                ...state,
                books: [...state.books, action.data]
            }
        case DELETE_BOOKS:
            return {
                ...state,
                books: []
            }
        default:
            return state
    }
}

export default user;