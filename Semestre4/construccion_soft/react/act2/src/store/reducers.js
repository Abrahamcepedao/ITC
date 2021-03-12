import { combineReducers } from "redux"

import cities from "./cities/reducer";
import user from "./user/reducer";
import books from "./books/reducer";
import login from "./auth/reducer"

const rootReducer = combineReducers({
    citiesState: cities,
    userState: user,
    booksState: books,
    loginState: login
})

export default rootReducer