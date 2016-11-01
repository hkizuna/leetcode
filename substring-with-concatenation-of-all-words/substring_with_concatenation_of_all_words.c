#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool
cmp (char *s, char *t)
{
  while (*s && *s == *t) {
    s++;
    t++;
  }
  return *s == *t ? true : false;
}

char *
cpy (char *s, int start, int end)
{
  char *t = malloc((end-start) * sizeof(char)), *ref = t;
  while (start < end) {
    *t++ =  s[start++];
  }
  *t = '\0';
  return ref;
}

bool
is_contain (char *s, int start, int end, char **words, int size)
{
  int n = (int) strlen(words[0]);
  int *map = malloc(size * sizeof(int));
  for (int i = 0; i < size; i++) {
    map[i] = 0;
  }
  while (start < end) {
    char *t = cpy(s, start, start + n);
    for (int i = 0; i < size; i++) {
      char *tt = words[i];
      if (cmp(t, tt)) {
        map[i] += 1;
      }
    }
    free(t);
    start += n;
  }
  for (int i = 0; i < size; i++) {
    if (map[i] != 1) return false;
  }
  free(map);
  return true;
}

int *
find_substring (char *s, char **words, int size, int *rsize)
{
  int m = (int) strlen(words[0]);
  int n = m * size;
  int l = (int) strlen(s);
  if (l < n) {
    return NULL;
  }
  int i = 0;
  int *all = malloc(l * sizeof(int));
  while (i + n <= l) {
    if (is_contain(s, i, i + n, words, size)) {
      all[*rsize] = i;
      (*rsize)++;
      i += m;
    } 
    else {
      i++;
    }
  }
  return all;
}

int
main (int argc, char **argv)
{
  char *s = "baauxdthqwzuleorburxbkrksgpgchndjqygttnmsnidtwuutotwylhqtwyvfoboebvxukjozrssqonjcifctmsmktkphlelmbkinwxnnrhfhwokfwmaihptazkjmowargifchusybxgyosfkgfupunpvyahowhgdsnhbhbakziipcpzivtyrjpnjqwxogftaubbbcdmdnwspmtajpaayrpjjogyworwiszmxfacswxkkqkthmwhdnqnbzlzncxxxxjwclywixguosoxemfizvxduicjmajlzujbgizofgivyytdmanmxkrsuvdixmwwjfzpnzfvhpsfqnkcnxqljjfffkoezkbircxfdecktwslkcozceklqrrvchzdtclkhkrmotzjqrvctlbvrojhfcejjgmcizmrjgezzdlrwgvptxnknyssawejcsnnsbgdhmdjroanwyfpvuzistcssidwbqjvrsyzediytklpisgfminebsyvabsdtdylvzmccuaygnnrgwwsemzhezdgbvkuykhwltyqpaoyndptzlodxnndmqkplwmlivjwpjmgjcexftshhgmgvzkkpwbcupqelzacloiuqptwkofrurasrkegiflcvbgichknvuiojdmwrrpoipizbmijrtlouuwydimadwoozamtrcjatrbvdjewcsnymjxrujrxhgniiabaemcxddugnzfrtsqfdnyxypwfvmpgorgsdkrjpmrclwwgomnublrbaqiycxeqqmkwwbflnwqatmijavfdgzehpmhtlljcxvyvwdgmbyowmximsnrzmvidjpwvchxbcxwzaenbfbyraggtvxuivelevkbxryauvwvxcibhlbbmjhfeebozfcgamhzdizxfxsdzcgjohkasrhwxinzpphpboogwpeemyjnbpwryirqzaozibazshotveautgyhgjuhytyybrodtecdgccalqugwwcrecykltujoujpmzsfewlmanmleiscewukzsvknpwbjftxflfliqxkdlwjuqmamglnagyoxwrgdkgkwlvgbuqggoqaeeatkngktgascszicfsasqivkbbqprswvvphivueeuwgoxotejvwzerjhtcwmuukrjtahnelkctyaktgtpduvwdcrhaeevqvgjvnzbajgujggfmzurtroyvfivlmsdhznfomipxolgwrllshcnysnvavrnjlrtmgadsisrzfxvylgqslftfsohqhxzvoshuskodefclexjrgbmtgfabvirffscvnjrfwhkcomqumzmudypjfpmczdjgwlbjxuqvdbxrpnmdpyxsyoddeqfdvpmtcpczkvunyuhpjvtytssthywnqdqlscfvsjweertelauuxnvqhpjonhbdlurfywcshzymqsqdumzszukhkwxzdbdqxuwxsaqzzonrigufswxssjbcfaeldhdadzyxaqwbgmtpspwkntegc";
  char *words[] = {"aayrpjjogyworwiszmxfacsw","jvrsyzediytklpisgfminebs","wxogftaubbbcdmdnwspmtajp","nhbhbakziipcpzivtyrjpnjq","nmxkrsuvdixmwwjfzpnzfvhp","cjmajlzujbgizofgivyytdma","vptxnknyssawejcsnnsbgdhm","sfqnkcnxqljjfffkoezkbirc","kphlelmbkinwxnnrhfhwokfw","zdtclkhkrmotzjqrvctlbvro","jwclywixguosoxemfizvxdui","vxukjozrssqonjcifctmsmkt","djroanwyfpvuzistcssidwbq","idtwuutotwylhqtwyvfoboeb","wsemzhezdgbvkuykhwltyqpa","xfdecktwslkcozceklqrrvch","bcupqelzacloiuqptwkofrur","xgyosfkgfupunpvyahowhgds","jhfcejjgmcizmrjgezzdlrwg","rxbkrksgpgchndjqygttnmsn","maihptazkjmowargifchusyb","oyndptzlodxnndmqkplwmliv","jwpjmgjcexftshhgmgvzkkpw","yvabsdtdylvzmccuaygnnrgw","xkkqkthmwhdnqnbzlzncxxxx"};
  int size = 0;
  int *all = find_substring(s, words, sizeof(words)/sizeof(char *), &size);
  for (int i = 0; i < size; i++) {
    printf("%d\n", all[i]);
  }
}
