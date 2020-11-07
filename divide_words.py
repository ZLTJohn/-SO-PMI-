import jieba
jieba.enable_paddle()
f = open('review.input','r',encoding='utf-8')
strs = f.readlines()
f.close()
strs.pop(0)
f = open('processed.txt','w',encoding='utf-8')
pseeds = ['赞','不错','很好','感谢','好','快','满意','好吃']
nseeds = ['慢','恶心','难吃','不好','错误','差','糟糕','无语']
f1 = open('pseed.txt','w',encoding='utf-8')
f2 = open('nseed.txt','w',encoding='utf-8')
for seed in pseeds:
    jieba.add_word(seed)
    f1.write(seed)
    f1.write(' ')
for seed in nseeds:
    f2.write(seed)
    f2.write(' ')
    jieba.add_word(seed)
for str in strs:
        seg_list = jieba.cut(str,use_paddle=True)
        str_out=list(seg_list)
        for s in str_out:
            f.write(s+' ')
        f.write('\n')
f.close()
