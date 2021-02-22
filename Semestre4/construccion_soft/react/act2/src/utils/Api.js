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
}

export default Api