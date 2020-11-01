import React from "react";
import styled from "styled-components"; //importando o styled

export default function Humidity({ humidity }) {
  return (
    <>
      <Container>
        <h3>Umidade Atual:</h3>
        <span>{humidity}</span>
      </Container>
    </>
  );
}

const Container = styled.div`
  -webkit-box-shadow: 5px 5px 18px 0px rgba(0, 0, 0, 0.73);
  box-shadow: 5px 5px 18px 0px rgba(0, 0, 0, 0.73);
  background-color: white;
  border-radius: 50%;
  display: flex;
  justify-content: center;
  align-items: center;
  height: 360px;
  width: 360px;
  flex-direction: column;
  h3 {
    font-size: 28px;

    font-weight: 600;
  }
  span {
    margin-top: 50px;
    font-size: 24px;
    font-weight: 600;
  }
`;
