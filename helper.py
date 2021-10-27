def read_file(file_name, take_int=False):
    rows = []
    with open(file_name) as inp_file:
        for rr in inp_file:
            if rr[-1] == '\n':
                el = rr[:-1]
            else:
                el = rr
            if take_int:
                el = int(el)
            rows.append(el)
    return rows