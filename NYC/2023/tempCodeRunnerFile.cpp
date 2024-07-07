cout << prePoss.size() << endl;
    it = prePoss.begin();
    for(;it != prePoss.end(); it++){
        cout << (*it)*10 + maxPost << " ";
    }
    cout << endl;
    
    if(prePoss.size()>0){
        it = tempPoss.begin();
        intersect=*it;
        for(; it != tempPoss.end() ; it++){
            for(int ival: intersect){
                isMatch = false;
                for(int pval: *it){
                    if(ival == pval){
                        isMatch = true;
                        break;
                    }
                }
                if(!isMatch){
                    intersect.erase(ival)
                }
            }
        }        
    }