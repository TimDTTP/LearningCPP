
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

struct TestCase {
  std::string word;
  int expected;
};

TestCase test1() {
  TestCase obj;
  obj.word = "aba";
  obj.expected = 4;

  return obj;
}

TestCase test2() {
  TestCase obj;
  obj.word = "aabb";
  obj.expected = 9;

  return obj;
}

TestCase test3() {
  TestCase obj;
  obj.word = "he";
  obj.expected = 2;

  return obj;
}

TestCase test4() {
  TestCase obj;
  obj.word =
      "iibhicfjiejfcejhaiebdcefjdcjfafcdcaiecddhfjaffidihdcbacfgjacbdjddfcjhaib"
      "hebfijbabheifjeejfgbgccfgibabbejaieafiejibghicdfhbcgjceejgijiebjdbbhhicd"
      "jggegacdcbiaacdijgbhdjacdbddgbfccfhiiddjadhebagedhjcfgaajcdfedfjfbhaaehe"
      "dfggeiddjcccefbbfjejfcjbgcjcchijigfgadfcgfjchjadfihbdbdibbbbdgjiidhajggb"
      "hdfgccgegbgehibahfiebiefhdghbbabagjbdfieehdcjchadjghbbgcdgfgjifeggicefac"
      "iiigehiehdchcjfdghfbbfdihjhajgbddggjfafjdcbfhhgbaididcaadcafhabgdabdgeda"
      "fhhehbjbefedjjfejbbbhaeeceejifdecbjhjihafbfigbjhgedaeiebjadjbdhbhhhhabch"
      "iedbieabeegfabijfeccbdjefggajiejhigdhbfjbifjchhbdfffbddgcjadbaahbagedace"
      "fjfchadjdabcaehahbjahfchbcgchjbddjcbebjcgjabiiibdeaedajdhiagebaichdciigg"
      "edbigeibgadjbgabafjiifbhceaaiefcdgfcbcahhhicegfiiggbbabfabajeeddgfdeafcc"
      "ibaihahcbifeeeabdicihhahfjjidhbfecgehhggcebjbcbihccfdejfjdjcbfegiajfciij"
      "dfdfaecbbccdbhechgeedbigefdjhcdbghgafebahaceghgbaheheigjhgchhjafjdacegfc"
      "jbidbajejhghfdccebiaaehcegbadgbicjcbhjbdfigceajhbaafgebfaabfjibedeghicbd"
      "geeeccbadebdcffhcafdcfgcdiiheidbaadaiifefeijhhebiebgahjbefejbiebebcjjaci"
      "fcbaagdbddigbacdfeidajefahbfcidiaffbaaaddhgcjbcebaafcbechbaagidgeegcaahi"
      "hedaheacbahbbeigchgdhachcffdbjejehebbahcfdaabiefecabdffgfdbjbeehfgabebif"
      "cjdajjgbfdihbagbidbefdjdbedchhdaigghehfdfajcefecdhdghhbdicidedeeicciehcj"
      "ecehfjiaebecdaefdgdjahgfdjgbegiaejcghjcabcifbaigjbdgfiaaffgddeccedcgecfe"
      "eiceajhcfejhecdcfdhjjeiafgbbebfdacjcebjebahgbbbajedeidbaeeijafdaidgccfdc"
      "dgjeeibdbdgejgbjeegegjjgabdgjghicfeecdhegfhdhhbihjefhfadiigefefjcdijhche"
      "ehbggbhhcgchchafgdgedjdhdiijcieaeddbhedfeidhbifjddgahjafjfaiehabfhejhjgi"
      "gfhcfdjfdfhggjeaiijeiajgghjijjicibfedafgciffgifbeajgddbejffhcdafchbecabi"
      "ecedaehggaacabhgfeihaabehggbfjcgajgjfceaifcigcfhbbbdcieiihadabhhfaejjbdf"
      "fhabehhefadcaabdffeggfhgcgifcgaceacccgaaiagaafcdijdggeaeahafhjichecgddbi"
      "icgdjbaajcciehfihdgdihiicehdafdadegabbifddggahgbiedfdbhfebiggdcijajgedef"
      "jbfcjedijjbagcifjfcacjfhahjjbdgfaifehfhhbfbceecccigfbfjhcgbdgjhadfcjicda"
      "ggjbhfaaeahihiehaabbgfebcdgdbihbhfheajedigfigeebdhigaicgbgbhjgigddfagiea"
      "chdfijbbbcigebhhheaiicjdaabjaidjjibcjdjbbgccecdbdfdachaeigdeihbdijceggjc"
      "cgfcigcefgebehbhfdjccjadfhdeejgaddhdfihjcbibbjcabbcgddfffgcbhehjggjafdjd"
      "dcebfajjccfhedbiecbbbjbceiifcfddiaiffacedgfgjbjhcbahjeedfghbjijcceedcdga"
      "acccgdaichjhaffcfcfijjhchfiecgbajjjgacifffajhadgaicgdhdffijhjeaddgdjeagd"
      "ihjbfiffdbeheadbaicgcbhjgbddhbcagehffgecijdjejacafheheefhjfeihigjafddccg"
      "bcgjaehgjefidbhbifedgejcjhddfbfchegjagbagafihfceihijidejgegcfcdejfddchdf"
      "cdhhfifjefifaddcggaheiiicahjihhehjbiebiiaegbbbgfehiifgiddgdfgghjiehddgfg"
      "dgigbfeaefccfegajiaegaheffaiiejacjiifhgjcahbjdidiffbbdhjdifihfbhjaeehghb"
      "ccjbahbeifabcjiibejcjcdgceiigjcacjbicafadbejiecchfbajjhadcfhgbcbfeccjiii"
      "ejjhijdhidbadaagbihaeafiafibejcjdhbgibiagdhijhjeefeccdfaheejcdiiadfjeeae"
      "jeaaidiggjghggagcgcbffehadafhgegfcciegjbdiabagcffbfadecjaaeifgfidcfbhhib"
      "gbhfggjfgccdccabfaacbgjfijbgaaejjbhgifedcbafddiabfhehdabdjjiadgfjdjeaeca"
      "hhhgijdcfaajjjeegcfidfbbggcbbafeddjbieeahfaccjdfhjhdhddbfhhafagddhhgbgbh"
      "cfiefdhfdgjbbbjdddcdfjdagcichfijedffigeijjgchdiihadagjbgidcegfhaeaiheaac"
      "jhfhbdbfgajagececefddcadfbhihgjciaddgjiijbadehiddaighheigfghggcgagehjiaa"
      "hcgcfecheddehcijffgiidjjcfidjeifaicbaaiddjedhcihhabcidggjeaceehiiieecigf"
      "cibcffjdjbbbgieefhdieddjchegicigajdebieiiabdbadfdcjigegdcgdjbdbggjidajhb"
      "fcigihdefgfcfjidhdeejahfachiaaiiecfcgdbcdiiigbgbfbghfgfifhbeehegigfchafj"
      "bjgieeiechdbidcijfjeciechidfcfgfciaaafcbdgbhdbgdcijeddfbgchbgjeeggidiiga"
      "ijacejijfiejbhebicagcgjdbjefefegejdachfjjeaifeacadfcffeegbidaieicedjjihd"
      "igbjffcfedchhfhjcgjeceiaajgecifgdahcacjchjgafcfibjicegfahdgicbagaedacgag"
      "cijddgbbhiafeiaijcidebfbhjgaegdajjgiiediaejijfcdbjieaficdbddjgheageiffjf"
      "eggdghheijbdcbcfcicaccdhhcehfbiafcgdajeefjajijgbefjebehaffjhfgjifhheadgi"
      "jijgfefbgifbabjjbdfgfbhcgdgdcjcgdfjacebdhcacjfchhhegedceggdjjdaigbbcajhi"
      "ahffjbiajeahgibjecfdbffgjgeehacggjiejfhhjchcghicgggdbhacdfdadiggdcfifcbf"
      "aaecihagdeffhdhgehbjbabdadcgicdhjeecibeicjbbhahebjjgjjjjbhfcibcgehjbbgid"
      "dgciiaaaijadbaechjdjbfaiffbabjhggjecgggbdihifibadbafhfcbdaddaccjigjcdggh"
      "bbbcajccifecfbabaedaiaccdhihbffdegahhhaaiidhdijidfghcdddfgfihfdecijhjdie"
      "jjbhjjbeghhhejafhegjjhbecjgbcdbcjcgcdfedcehhecfcefbhagcchegabacedfdcagfb"
      "iebhfajhdedgfiebihdbfachfaaheichaffcdeefhacdiafdddhfhbbjjbifjegcefjegfbj"
      "dgfedfcbcddfeajjdadbhajjjacgahcjeeibiedhgedhccaiadadjcjjbaddiefbcegcgcjb"
      "egfadijicgjcedcjhhbgjijgjhbhhhjifdhddhgcefjjjihebffdfejjaajicfcdfdabjbfe"
      "fhjcjahidagbchddibjdgdcjfhhagfacfghdeagddbieeeifhbdjjdgafcfdbbgfadeigige"
      "fijjghggbecaidgaagefefcebgebeaajadjcfcfhgcdjcbbiegdhchcaheijcggajjbjfcic"
      "ahafjbbbahfeecejibgbfjeichffcdhfhfefciahjcbddbhaaijjfjchhbjicdhcccdccifd"
      "gfjehhjdecdcagijdddhggfhfbgagfefdfbabcdbiaeeiibgabfjheaajccfjjhjbijchafj"
      "fibdedegchdcbhieaiccegbacgdihdjigdcagaffhjghhejceaeaeiaadfhbgbdbdgjccjia"
      "cjijfjbecedeahcfbabjhiidihcjbgeefdiabgaiffabiajifcigfjgehcbjahbefjcadijh"
      "hhbgdfdhhdgbabjagfbcjfagffjdgaadfjibedjcjfhjbccdhbfdeaegefachbebjbiijcde"
      "ddbeiacdigbgbfaaiajhcccagehadjiibjfejdeacihhbgajcagbacabhcfdeifeiaegfgie"
      "ahbeifccahheifjjbfejgiadjbifebbaidaaaiiddibhaidbabhgfeijdafjafhcfbhdhjgd"
      "igddaeheheecbiighabcabjgbgbaiiccjgcgejafdhaaiadcdebegjaidhghdjahbihabaif"
      "cdjhhaicecaibiciejchiajfiegddejaehfbgcfaadegcjhjheecigjdfhiehcihjdiaiehc"
      "gcgdabcfedbcgbbecghidcejecbeffddhhfbidhbhdcfhcbcjbefdahifihfhdhgjbiaejfa"
      "fjfijdbiagfiijjhaiadehjgghcaajjefjddhbdhcbjahhaehiddffcfbdeggegdfeieafig"
      "ehhjccbjijegbcaahbejhahaiacghibhdjbiefgihbgecdajdfdjfdbjjceajdadhfgdfjib"
      "eeajibhijbfegfhiijjggcbcagffbcgieeechbghgbaagagehbghafhbideahghchfdjhfdb"
      "iebhigjedjibdcjfeedbgjbgcibbbhdigihjjcegcebejahefifigebefcdgegeabbcegffc"
      "dbafijfbabefecgafjdfhbiggeffbcfbjiciceebhgbeahghihahgefigdfjbcdbjgiabceg"
      "dhhaiiiabcbcdhcjccgggbadefieagcaegbdddcihciagagjeafdafeedjegaccgghifbhed"
      "agdgdidbgfcjadegcaebbbddaebjifbidfefbgbajdfacecaddgfebdiaagijedhjjfiggjc"
      "bjhhbciigfdecfebdddejjiafbbfchdbaehfaeaefbfjbcebheahdjafccaibbfiagfccidj"
      "hbicfachbahcecbgdieideaajhcfcgifebedeffdiibhceidaihjejjdacccgbfeggghgebb"
      "ebeadjahbhcjidjfcibeaehhbbbdfchbhjbichdfghgbejadffadhbjicijdjeidhbfbaacb"
      "jbiegifdfbeajajaejiafhfghjegbjafdgfiggjecaeehaicegcbfghfeeechaebdjbihdac"
      "jdebjjaigdajdbghhbjiigffedfdadfchcibaibgdfhhchgcaigbhbefgdcafhhghiadifed"
      "agedjbgcfcbigeafjffajhcdddchiidhhgdjijgcccgejcgdfagbceeeiidcbdfaigdeiafe"
      "gihdjgdiijbjifihaifbddibdjbhfejjjcdhabafdfbcajjdfjfhacadfbcbjhafbjgdgeii"
      "jjhffgdifjegfhehfbabhhjhadediggdaabibbhjajbajbddegjjagihbcefcfdegjbgaafd"
      "bahbjgabfhdbheebbajccfbaeiefbghjcefjjjhihiacagajfjaajicfggfbfggaheieddfd"
      "ihbdfchecdchcggabchbcahdiahdghhfabcdejbfgjgdaajhfdcbecbcbjbbjgchbgcdjgbh"
      "iaicccbhaihfbebaijiichhfgfahhhefieheihfcbcegiffhfjfgfjcdejiijhhedjdccdea"
      "bjahjjceecihbbfhdcdgccbdiffiiiacajdheadbeihcgabeaeegecjgdjafbjeggbafahff"
      "dcjafdbjaifeagefjdcfabibbgdbfejgahjhibbdacbiggjaacihidjdfaidhjiihbcbfcbb"
      "cfijgcchbgedaiicjfiiicbbbbdihgdbgbjfgibbfaacjfhcehfadbabbgjcdijiidehjjgc"
      "iiceedibbjidacbchcihiifcihccjgcfahaecgjdijgeegdgcgejjiadeijgdeedjdbdebjh"
      "ddgciiegddfabfaccbdcjggiidjfehdgcegdahecejdifcedijajigcdhdjhbdiacehiegbd"
      "bhhihjejgahjecgdciabjgcegjiegaiibfjgafaacbjabcddghcegjeibhjfcgahdedeifbd"
      "bhiiiffjbhieaadfcebdficfabbifjbjjfdaahchighcfjgjhchcghejjdbghhecgdahjhaj"
      "dcdfidgdehjjeehidhgabeidejbcjcjbdigeegabahfcjjfdgiaadidfjigdfhbgejfifhid"
      "dcahagdabdaaeagifgjahjhdgajfhfffijjfgdibdafjhiiihbddfbgjfjbddbiddcihhdhd"
      "adhfhbjbhghbadecfiegfichjcfdedbiaeigcbbgdcicajbfifjdbbdfhddfegiiebcccbjf"
      "gibjgjhahihcacchefhddbefgchcecjhaebgabfjiciichecggidcgjggdcagaibdichdfcc"
      "hhbjgciijbbjihcdhgcijeibaggiifiiafhhebbabhhhccigbaafjjjjfaeeebcgjcfjhjib"
      "beihfbfbbiajafbjiciibfbgfeaacfcfgbbddfagdehbbdabbbgdfiagicgehaffhhiggdea"
      "fjajfejcbjfjchigfhheegbhjhiccaghehjdeihgdaibdfdfeaefaeijhhabbjebcfgdaege"
      "jhhdedagehebfebjigiijfiibdcgadecgfgdceiihiebjijhhdhhjheaffhchggeiajiggef"
      "aheacibejefdjfajjccjfaeifabaicigfhdaeddehcdeahgjfbaffcchjajdgicdbeiebied"
      "afjcifegadecigahhaggabddfgadcbgdhaechadgbjefajdbcjiddjhefjiiadjifcfiiifg"
      "jejjeihbhciajfjifadejcdbdgagagchcbfaehcdhcafdeegbgfdbdjedefchcbiiihfhejg"
      "iijffbajcfgdgdhegicbefcbahhfgfbdegjefjejbeefahdggibhaaigibbedghhgcchjfbg"
      "aicdaejjcijebifbbacehdfbbaaajciejgeecgjdhieiaadeeejieagecjijbgdejecbcccj"
      "bgjadabiiidgegjhchaiacegaiaeeagbfjdficbgifefjagideiibbcfgcacdcgichdiaeje"
      "jahgiiaiidfhfadaagjcchiajchhcghjgfiddffegdcfgbegiaideebffiiabjjhbcecgcag"
      "bfcchcbcgcbaijfdbfghagdffbhbjajdcjidiihejdjbcaaaeaaibdagjfagaajhiijcbiib"
      "ifgdfihfdahgggecagbgghhdjgjgjhbiihhjgiabdibfidfecgfjhghebbaadbihceeicdca"
      "hheddddebdjfigcgdejjdbbcijijfchdedibjegaeahccfhhcfcejhiihaacgdbigedebadb"
      "iafadchjcjciibaaafgacadfgbaebcbceedaihhebfjfefjigdfhhbdbhcahdbjigahafeid"
      "ehgbdiihhdaahjddiafghagdfabcdafdjgdahhehjheibghjhbgjchcbgdahafaiebajgggb"
      "dgbfjdjghjfefhhabjfcbgbabedfidafiheigjjgjicajaeigcbafcbijhhbgddhggbechbj"
      "gcadffhcdffgfbgffdbbhdfgggcbgjdfbggefhbbaccahfdaibdcggaddacchghhbdafjaea"
      "fjeiefejddihhccfdaddbhibjaddehjbeibjidedajigjeeefhehejjjdffggfjdbhgcdigf"
      "ejabjjicbcheiffigdgdeejjecbajdffecagfaejdhicaagbfjjddggagahjdfgcjiihibfb"
      "iahhcgggjagdeiifhccdbbafeefgfdadgbchcdicefhejidfaeaddfichdebbdeeajfdhffa"
      "gchebhhhbbeaahefaeccfdfdagahhadfifgbdfjbffbfjehfieddbhhbfdccahiadgbfijhc"
      "bjjgcchhdecafafbefbfeahjefbhhgffjagijbdehiiefdfejfbfjeeiacgajabgafdfiejf"
      "ffdhbgdhhfehbehfiiieehbegjhijaidcifcdceibibgjfjbdifdhdciadhagdgdgebhjabg"
      "bdafcaajeiiifaddaicaideiebhfehehebfcbaaebhcejfechaiiifbbbbdfdfcdfdbheiid"
      "ffhbffdaeabbgjgfgcghchigeaehbfcdfgcfhgifjjejcdjehjhjjibbjbbageheihgeehee"
      "ejajhafhahcddiajgbbhhhgfafhccdjjajeccbijiaadhecfejgdjfacghfjjdciiagdgecf"
      "ifbefifhdcjiigchcjggffghcbcefhafhadccahbahdgeeafjfdiehhdijjcjccjcbeeacci"
      "ebffjeaedacfdihgcdiihegefbeeedeeddihahhjhafgiccjhjjfifecacajdegbjfeaicei"
      "hhabdhjfdhjjcgdaedccbefhddicdgbeigdhhcgegghijdeedfgaigeijejgegeahifabbbc"
      "ihjfcechcjibfdghgbhhccfaafaifaebfcjbafgfjaiiedecefgighehjihhjdhhgbaijfje"
      "bcbejgfjfchdacadjcibaghgeiifdjdcecbbgbeaefbcjegecebdfjajfhjbejejdeadaccf"
      "gbfbhbchehfiiijdhdhbfcjjdjbjhijdfdecdeecjcbiacbjdcaahahaceejhaifgefcdhah"
      "cgbdbgecefgbdjfcdgbaehhdeddcbbjdhahadjfdefffehahageggbcbgjgfaajjeagbbeeh"
      "hiie";
  obj.expected = 2;

  return obj;
}

class Solution {
public:
  long long wonderfulSubstrings(std::string word) {
    int counter{0};

    // loop through string
    for (int start{0}; start < word.size(); ++start) {
      std::unordered_map<char, int> map{};
      std::unordered_set<char> isOdd{};

      // loop through the rest of string
      for (int rest{start}; rest < word.size(); ++rest) {
        // increment char in map
        ++map[word[rest]];

        // if odd add to set
        if (map[word[rest]] % 2 != 0)
          isOdd.insert(word[rest]);
        else
          isOdd.erase(word[rest]);

        // check # of odd
        if (isOdd.size() <= 1)
          ++counter;
      }
    }

    return counter;
  }
};

class Online {
public:
  long long wonderfulSubstrings(std::string word) {
    std::unordered_map<int, int> count{};
    int mask = 0;
    count[0] = 1;
    long long result = 0;

    for (char ch : word) {
      mask ^= 1 << (ch - 'a');
      result += count[mask];
      for (int i{0}; i < 10; ++i) {
        result += count[mask ^ (1 << i)];
      }
      ++count[mask];
    }

    return result;
  }
};

int main() {
  Online answer = Online();

  TestCase input{test4()};
  long long actual{answer.wonderfulSubstrings(input.word)};

  std::cout << "Expected: " << '\n' << input.expected << '\n';
  std::cout << "Actual: " << '\n' << actual << '\n';

  return 0;
}
