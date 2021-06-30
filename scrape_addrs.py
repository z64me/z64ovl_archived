import sys

versions = ['OOT_DEBUG', 'OOT_U_1_0', 'MM_U_1_0', 'MM_J_1_0', 'MM_DEBUG']

if len(sys.argv) != 4 or sys.argv[2] not in versions or sys.argv[3] not in versions:
    print('Usage: scrape_addrs.py z64_functions.h map_from map_to')
    print('where map_from and map_to are one of')
    print(', '.join(versions))
    sys.exit(1)

with open(sys.argv[1], 'r') as f:
    context = None
    symbol = None
    symaddrs = {}
    gotone = False
    printed = False
    for l in f:
        l = l.strip()
        if l.startswith('#if') or l.startswith('#elif'):
            for v in versions:
                if l.endswith(v):
                    context = v
        elif l.startswith('#endif'):
            if gotone and not printed:
                print(symaddrs.get(sys.argv[2], 'NULL') + '\t' + symaddrs.get(sys.argv[3], 'NULL'))
            context = None
            symbol = None
            symaddrs = {}
            gotone = False
            printed = False
        if l.startswith('asm("') and l.endswith('");'):
            if context is None:
                raise RuntimeError('asm outside version context: ' + l)
            l = l[5:-3]
            toks = l.split('=')
            if len(toks) != 2:
                raise RuntimeError('Bad asm formatting: ' + l)
            s = toks[0].strip()
            a = toks[1].strip()
            if not a.startswith('0x'):
                raise RuntimeError('Bad asm formatting: ' + l)
            if symbol is None:
                symbol = s
            else:
                if symbol != s:
                    raise RuntimeError('Looking for addresses for ' + symbol 
                        + ', but found addr for ' + s + '! ' + l)
            if context in symaddrs.keys():
                raise RuntimeError('Duplicate definitions for ' + symbol + ' '
                    + context + '! ' + l)
            symaddrs[context] = a
            gotone = True
            if sys.argv[2] in symaddrs.keys() and sys.argv[3] in symaddrs.keys():
                print(symaddrs[sys.argv[2]] + '\t' + symaddrs[sys.argv[3]])
                printed = True
        
