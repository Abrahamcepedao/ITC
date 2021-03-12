const axios = require('axios');

export const endpoint = "https://openlibrary.org/isbn/"

//b043df5a
class Api {

    static GET = (url, onSuccess=()=>{} ) => {
        axios.get(endpoint + url + ".json")
          .then(function (response) {
            console.log(endpoint + url + ".json");
            console.log(response)
            onSuccess(response.data)
          })
          .catch(function (error) {
            console.log(endpoint + url + ".json");
            console.log(error);
          })
          .then(function () {
            // always executed
          });  
        
    }

    static POST = (url, data) => {
        
        
    }


}

const API_URL = "http://0.0.0.0:5000"
const axiosApi = axios.create({
  baseURL: API_URL
})

export async function post(url, data, token=false, config = {}){
  if(localStorage.getItem("auth")){
    axiosApi.defaults.headers.common["Authorization"] = "Basic " + JSON.parse(localStorage.getItem("auth")).authToken
  }

  return axiosApi
    .post(url, { ...config})
    .then(response => response.data)
}


export default Api