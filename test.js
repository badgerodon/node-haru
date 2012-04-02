var haru = require("./build/Release/haru"),
  Doc = haru.Doc;

var doc = new Doc();
doc.addPage();
doc.saveToFile("test.pdf");
console.log(doc);
