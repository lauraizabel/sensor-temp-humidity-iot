import firebase from "firebase";

const firebaseProjectName = "dht11-f269b";

const config = {
  apiKey: "AIzaSyDfj2_TEdIEiZ-FaOJlJR0G5u9tsaO8IkM",
  authDomain: `${firebaseProjectName}.firebaseapp.com`,
  databaseURL: `https://${firebaseProjectName}.firebaseio.com`,
  projectId: `${firebaseProjectName}`,
};

firebase.initializeApp(config);

export default firebase;
