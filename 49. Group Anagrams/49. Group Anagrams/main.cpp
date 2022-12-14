//
//  main.cpp
//  49. Group Anagrams
//
//  Created by Артём Lazemir on 11.12.2022.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash_table;
        for (const auto& s : strs) {
            auto temp = s;
            sort(temp.begin(), temp.end());
            hash_table[temp].push_back(s);
        }
        
        vector<vector<string>> res;
        for (const auto& el : hash_table) {
            res.push_back(el.second);
        }
        
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution sol;

    vector<string> strs = {"shuffled","lacquered","efficacious","michigander","corruptness","internals","converter","speeds","rebellion","transceivers","electroencephalogram","crematories","bespoken","complainant","flotations","nev","blindfolding","corresponds","optionally","aggravating","gratifying","healthfulness","characterizing","dole","fantasies","bulks","responsibly","exploiting","confluences","header","dunno","saddam","adulate","spoken","bargained","funiculars","enlargements","mastered","expended","zambians","muggiest","riveted","junketing","shrewish","issachar","wallpapered","bridges","efficacious","cogitation","parabola","inheres","song","chock","surfing","windy","richer","shields","rehash","autobiographical","idiotic","discipline","keyword","proliferation","hollower","exposing","britain","fred","salarying","misplaying","gallbladder","czechoslovakia","burying","deprivation","lubricated","androids","hurtle","kitty","attach","subsidies","tumbled","unseemliest","impelling","surmise","blundered","etching","stuccoes","windiest","monorail","raided","comedians","theodora","muhammadans","sillies","unlocking","lubricating","desperados","vine","purposeless","calmest","loopy","confluences","clings","today","mountaineer","son","axiomatic","thur","ideograph","document","rudolf","joviality","crystals","moodiest","footprints","net","taney","crane","psycho","quantified","aisle","aimee","vegetarianism","canes","twining","butler","transporters","cohere","wilts","outlines","imbecile","passages","godunov","sunken","maneuvers","papyruses","slowed","residuals","tarpaulins","devour","callus","aldebaran","wraiths","outplay","psychoanalyst","flicking","congealing","unsteadier","smoother","bavarian","savvy","wino","tortola","stiflings","deprecation","iguassu","surnames","chit","fraud","strong","camel","undulate","jiggling","lars","singsonging","canny","someway","overtaken","sonja","rapacity","scotch","discus","spill","boated","americanized","phoneyed","nonprofessional","excessive","nuisance","haddock","fared","jibes","lintels","nurturing","falls","testimonial","pluralism","cookeries","cocksure","cassock","appraiser","contingent","barbarous","shoo","groundings","tulsa","hughes","fiver","taces","compatriot","cockpit","sepoy","naughties","topeka","decadents","rangers","topaz","kr","accoladed","palmed","jackknifes","overbore","blintze","shari","corroborations","mortgagees","tylenol","rockies","caesar","estimations","disconnects","coordinating","satinwood","octopus","smithsonian","dustiness","subscript","compacting","sanctuary","restarting","palmist","johnie","winos","conurbations","contrived","crumby","demavend","blooding","electrodes","composed","wheres","clements","ululate","basketball","cattlemen","callus","toolboxes","harelips","garaged","fuller","stubborn","scald","devotion","revolvers","kernels","lean","adversaries","floe","uninvited","umiaks","crackup","molested","santiago","contraltos","bethany","exhortations","preferential","gina","processor","beleaguering","fountainhead","politicking","denounces","eats","zodiacs","lubricated","prisoning","chautauqua","apparently","apiaries","lawrence","ellis","vampired","falsifiable","shaker","impecuniousness","maurice","vaginas","fran","cobain","angkor","discernment","numbs","bridges","novelette","renumbering","multiplicand","gluey","tots","garment","outran","disrespects","chino","pennsylvania","puff","chilly","roosted","fuses","concede","unimplemented","misogynist","disheveling","wiggler","penciling","storage","thoroughbreds","copiously","unidentifiable","warpaths","detriments","wantoning","welling","philosophizes","proprietorship","crumbliest","forgather","hemlocks","evangeline","abelson","extant","hijacking","repelling","stockholder","rebuking","stagnates","mechanization","shenyang","obeisance","english","erythrocyte","marring","regenerated","spinster","pest","forgathered","projectionist","match","smolder","rhinos","libretti","astutely","recuperates","outsources","vole","maestros","viewers","imprecision","astrophysicist","aristotelian","impressing","picnicked","minimalism","commas","ladled","gobbles","aborts","ahem","lira","surreptitious","corpses","london","hallucination","hendricks","traumata","anchovy","medication","reexamine","stabilization","jackboot","insular","floated","silkier","entertains","barren","savvier","volatile","amethysts","feuds","cheddar","cogs","trinities","underpasses","whoopee","cult","housing","fussbudgets","laminated","regress","boeotian","fugitive","anthers","nebraska","torch","declassify","tijuana","badges","cohan","stylish","formosan","lifestyles","impresario","love","errata","teletypewriters","resembled","cork","weaver","darlene","preoccupied","cage","faun","reclassifies","confinements","evolution","jayne","syndicate","soaping","provincials","regional","squabble","apricot","totes","herbart","beards","carpetbagged","assignable","henpecks","coating","amplified","insulation","smooths","parliament","sahara","bursitis","lingos","wherewithal","inoffensively","overcrowds","bhutan","disarrange","zippy","flosses","parnell","erratas","sidings","clapboards","confederated","palliative","wirelesses","etruscans","neonates","clayey","vaccinating","peskiest","liable","bibliographical","squidded","hausdorff","lumberyard","blythe","pillions","fiddlesticks","sarong","scarfed","reformer","gunrunning","sweaters","entreats","wicca","tennis","quilt","canisters","frankincense","unbar","neighed","cicadas","bighorns","tittles","dimaggio","costuming","judas","paints","pastorals","carib","glamored","cantering","demotes","currying","excommunicating","thwarting","freebase","niagara","fortification","buttercups","survey","barracudas"};
    auto res = sol.groupAnagrams(strs);
    
    return 0;
}
