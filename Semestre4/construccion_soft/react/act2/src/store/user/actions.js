import { NAME, F_LASTNAME, M_LASTNAME, EMAIL, DATE } from "./actionType";

export const setName = (data) => {
    /* localStorage.setItem("city", JSON.stringify(city)); */
    console.log("data: ", data)
    return {
        type: NAME,
        data: data
    }
};

export const setFLastName = (data) => {
    return {
        type: F_LASTNAME,
        data: data
    }
};

export const setMLastName = (data) => {
    return {
        type: M_LASTNAME,
        data: data
    }
};

export const setEmail = (data) => {
    return {
        type: EMAIL,
        data: data
    }
};

export const setDate = (data) => {
    return {
        type: DATE,
        data: data
    }
};
