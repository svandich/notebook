TYPST  ?= typst
PYTHON ?= python3

MAIN := main.typ
PDF  := notebook.pdf

SNIPPETS := $(shell find lib -type f)
STAMP    := .hashes.stamp

.PHONY: all hashes watch clean distclean

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

$(PDF): $(MAIN) template.typ theme.xml logo.svg $(STAMP) stats.json
	$(TYPST) compile $(MAIN) $@

watch: $(STAMP) stats.json
	$(TYPST) watch $(MAIN) $(PDF)

clean:
	rm -f $(PDF) $(STAMP)
	rm -rf hashes

# Also drops the placeholder stats.json.
distclean: clean
	rm -f stats.json
