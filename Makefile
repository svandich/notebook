TYPST  ?= typst
PYTHON ?= python3

MAIN := main.typ
PDF  := notebook.pdf

# Print-optimized builds (no transparency or color emoji, so pdftops keeps
# them as vectors). PRINT_PAPER is the printer's paper: us-letter or a4.
# Pick it with a word after the target: `make print a4`, `make horizontal letter`.
PRINT_PAPER ?= us-letter
ifneq ($(filter a4,$(MAKECMDGOALS)),)
PRINT_PAPER := a4
endif
ifneq ($(filter letter us-letter,$(MAKECMDGOALS)),)
PRINT_PAPER := us-letter
endif
HORIZONTAL  := notebook-horizontal.pdf
VERTICAL    := notebook-vertical.pdf

SNIPPETS := $(shell find lib -type f)
STAMP    := .hashes.stamp

.PHONY: all horizontal vertical print hashes watch clean distclean \
        a4 letter us-letter FORCE

all: $(PDF)

# Recompute the line hashes whenever a snippet or the script changes.
# The stamp stands in for the many files under hashes/.
hashes: $(STAMP)

$(STAMP): preprocess.py $(SNIPPETS)
	$(PYTHON) preprocess.py
	@touch $@

# The template reads stats.json to mark verified snippets with a green dot.
# We are not running the judge, so an empty list stands in for it; a real
# stats.json (from CI or a manual oj-verify run) is left alone.
stats.json:
	@echo '[]' > $@

DEPS := $(MAIN) template.typ theme.xml logo.svg $(STAMP) stats.json

$(PDF): $(DEPS)
	$(TYPST) compile $(MAIN) $@

horizontal: $(HORIZONTAL)
vertical: $(VERTICAL)
print: $(HORIZONTAL) $(VERTICAL)

# No-op targets: they only select PRINT_PAPER above.
a4 letter us-letter:
	@:

# The paper is not in the file name, so make cannot tell an a4 build from a
# letter one. FORCE rebuilds them every time instead of keeping a stale paper.
FORCE:

# Print with `duplex -l file.ps` (landscape)
$(HORIZONTAL): $(DEPS) FORCE
	$(TYPST) compile --input orientation=landscape --input paper=$(PRINT_PAPER) --input print=true $(MAIN) $@

# Print with `duplex file.ps` (portrait)
$(VERTICAL): $(DEPS) FORCE
	$(TYPST) compile --input orientation=portrait --input paper=$(PRINT_PAPER) --input print=true $(MAIN) $@

watch: $(STAMP) stats.json
	$(TYPST) watch $(MAIN) $(PDF)

clean:
	rm -f $(PDF) $(HORIZONTAL) $(VERTICAL) $(STAMP)
	rm -rf hashes

# Also drops the placeholder stats.json.
distclean: clean
	rm -f stats.json
