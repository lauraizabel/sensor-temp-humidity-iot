import React, { useState, useEffect } from "react";
import "./styles.css";
import styled from "styled-components";
import firebase from "./services/firebase";
import { FaTemperatureLow } from "react-icons/fa";
import { WiHumidity } from "react-icons/wi";
import Humidity from "./components/Humidity";
import Temperature from "./components/Temperature";

function App() {
  const [humidity, setHumidity] = useState();
  const [temperature, setTemperature] = useState();
  const [showHumidity, setShowHumidity] = useState(false);
  const [showTemperature, setShowTemperature] = useState(true);

  useEffect(() => {
    const getHumidity = firebase.database().ref("humidity");
    const getTemperature = firebase.database().ref("temperature");
    getHumidity.on("value", (valor) => {
      let value = valor.val();
      setHumidity(value.toFixed(2));
    });
    getTemperature.on("value", (valor) => {
      let value = valor.val();
      setTemperature(value.toFixed(2));
    });
  }, []);

  return (
    <>
      <Text>Monitoramento de Umidade e Temperatura</Text>
      <SetState>
        <div
          className={!showHumidity && showTemperature ? "active" : ""}
          onClick={() => {
            setShowHumidity(false);
            setShowTemperature(true);
          }}
        >
          <FaTemperatureLow size={36} />
        </div>
        <div
          className={!showTemperature && showHumidity ? "active" : ""}
          onClick={() => {
            setShowHumidity(true);
            setShowTemperature(false);
          }}
        >
          <WiHumidity size={36} />
        </div>
      </SetState>
      <Container>
        {showTemperature && <Temperature temperature={temperature} />}
        {showHumidity && <Humidity humidity={humidity} />}
      </Container>
    </>
  );
}

const Container = styled.div`
  width: 80%;
  height: 40vh;
  margin: 120px auto;
  display: flex;
  align-items: center;
  justify-content: center;
`;

const SetState = styled.div`
  display: flex;
  justify-content: center;
  align-items: center;
  margin-top: 40px;
  div {
    cursor: pointer;
    border: 1px solid #393e46;
    padding: 18px;
    border-radius: 8px;
    background-color: #364f6b;
    display: flex;
    justify-content: center;
    align-items: center;
    margin-right: 12px;
    svg {
      color: white;
    }
  }

  .active {
    border: 1px solid #393e46;
    background-color: #00adb5;
    svg {
      color: white;
    }
  }
`;

const Text = styled.h1`
  text-align: center;
  margin-top: 16px;
  font-size: 28px;
`;

export default App;
