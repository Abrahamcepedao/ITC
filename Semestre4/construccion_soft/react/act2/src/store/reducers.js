import { combineReducers } from "redux"

import cities from "./cities/reducer";
import user from "./user/reducer";
import books from "./books/reducer";

const rootReducer = combineReducers({
    citiesState: cities,
    userState: user,
    booksState: books
})

export default rootReducer