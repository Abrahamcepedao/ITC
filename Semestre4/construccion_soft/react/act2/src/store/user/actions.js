import { NAME, F_LASTNAME, M_LASTNAME, EMAIL, DATE } from "./actionType";

export const setName = (data) => {
    localStorage.setItem("name", data)
    console.log("data: ", data)
    return {
        type: NAME,
        data: data
    }
};

export const setFLastName = (data) => {
    localStorage.setItem("fLastName", data)
    return {
        type: F_LASTNAME,
        data: data
    }
};

export const setMLastName = (data) => {
    localStorage.setItem("mLastName", data)
    return {
        type: M_LASTNAME,
        data: data
    }
};

export const setEmail = (data) => {
    localStorage.setItem("email", data)
    return {
        type: EMAIL,
        data: data
    }
};

export const setDate = (data) => {
    localStorage.setItem("date", data)
    return {
        type: DATE,
        data: data
    }
};
