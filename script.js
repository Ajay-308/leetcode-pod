const express = require("express");
const bodyParser = require("body-parser");
const cors = require("cors");

const app = express();
app.use(cors()); // Allow requests from different origins
app.use(bodyParser.urlencoded({ extended: true }));
app.use(bodyParser.json());

app.post("/submit-form", (req, res) => {
  console.log("Received Form Data:", req.body);
  res.json({ message: "Form submitted successfully!", data: req.body });
});

app.listen(3000, () => {
  console.log("Server running on http://localhost:3000");
});
