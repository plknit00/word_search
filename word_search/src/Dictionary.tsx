import React from "react";

export interface Dictionary {
  confirmWordIfFound: (word: string) => boolean;
}

interface Word {
  word: string;
  isFound: boolean;
}

function getInitialDictionary(): Word[] {
  let list: Word[] = [];
  list.push({ word: "12", isFound: false });
  list.push({ word: "123", isFound: false });
  list.push({ word: "1234", isFound: false });
  return list;
}

export function DictionaryHook(): Dictionary {
  let [dict, updateDict] = React.useState(getInitialDictionary);

  function confirmWordIfFound(word: string): boolean {
    let newDict = [...dict];
    let foundWord = newDict.find((dictWord: Word) => {
      return dictWord.word === word && !dictWord.isFound;
    });
    if (!foundWord) {
      return false;
    }
    foundWord.isFound = true;
    updateDict(newDict);
    return true;
  }

  return { confirmWordIfFound };
}
