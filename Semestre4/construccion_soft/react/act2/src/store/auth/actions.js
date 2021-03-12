import { LOGIN_USER, SUCCESS_LOGIN_USER } from "./actionTypes";

export const loginUser = (email, password, onSuccess = () => {}, onError = () => {}) => {
    return {
        type:  LOGIN_USER,
        payload: {email, password, onSuccess, onError}
    }
}

export const tokenLogin = () => {
    return {
        type:  LOGIN_USER,
        payload: {email, password, onSuccess, onError}
    }
}

export const successLogin = (user) => {
    localStorage.setItem("auth", JSON.stringify(user))
    return {
        type:  SUCCESS_LOGIN_USER,
        payload: {}
    }
}
